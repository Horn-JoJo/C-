#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <cmath>

//宏定义align大小为4字节
#define DATA_ALIGN_SIZE 4
//将给定的size按照align进行向下对齐，将末位对齐为0 ? 还是不理解。。。
#define DATA_ALIGN_DOWN(size, align) ((size) & ~((align) - 1))

/*
将对应的某一个位进行清0 
val &= ~(1 << n): 将第n位清零

将对应的某一个位进行置1 
val |= (1 << n): 将第n位置1
*/

using namespace std;
typedef struct ringbuff {
    char* buff;
    unsigned int size;
    unsigned int rdId;//读索引readIndex
    unsigned int wrId;//写索引writeIndex
    unsigned int rptr;//读指针
    unsigned int wptr;//写指针
}ringbuff;
 
void Init(ringbuff* rb, char* buff, unsigned int size) {
    memset(rb, 0, sizeof(*rb));
    //size按照4字节对齐。
    rb->size = DATA_ALIGN_DOWN(size, DATA_ALIGN_SIZE);
    // rb->size = size;
    rb->buff = buff;
    rb->rdId = rb->rptr = 0;
    rb->wrId = rb->wptr = 0;
}
 
#define RINGBUFF_EMPTY     0
#define RINGBUFF_FULL      1  
#define RINGBUFF_HALFFULL  2 // ???

// 获得缓冲区所剩空闲个数：缓冲区长度 - 缓冲区存放数据的空间个数 
#define rb_free_size(rb) ((rb)->size - rb_data_size(rb)) 
 
static inline int32_t rb_state_get(ringbuff* rb) {
    //如果读写指针的值相等，则缓冲区为空；
    //如果读写指针相差n，则缓冲区为满；(写指针 == (读指针 异或 缓冲区长度))
    if (rb->rptr == rb->wptr) {
        //cout << "空的~" << endl;
        return RINGBUFF_EMPTY;
    }
    else if (rb->wptr == (rb->rptr xor rb->size)) {
        //cout << "满的~" << endl;
        return RINGBUFF_FULL;
    }
    else {
        //cout << "半空半满~" << endl;
        return RINGBUFF_HALFFULL;
    }
}
 
// 获取缓冲区所存储数据长度
int16_t rb_data_size(ringbuff* rb) {
    switch (rb_state_get(rb))
    {
    case RINGBUFF_EMPTY: {
        return 0;
    }
    case RINGBUFF_FULL: {
        return rb->size;
    }
    case RINGBUFF_HALFFULL:
        //return abs(int(rb->wrId - rb->rdId));
        if (rb->wptr >= rb->rptr) {
            return abs(int(rb->wptr - rb->rptr));
        }
        else {
            return rb->size - abs(int(rb->rptr - rb->wptr));
        }
        //return abs(int(rb->wptr - rb->rptr));
    }
 
    // never reach here
    return rb->size;
};
 
void write(ringbuff* rb, char* buf, unsigned int strlen)
{
    unsigned int pos = rb->wrId;//记录我们写指针的偏移
    unsigned int tmpPos = pos;//记录偏移位置
    int flag = 0;// ?
    unsigned int tlen = strlen;//写入的字符长度
    int empty_space = rb_free_size(rb);//存储剩余空间大小
    
    while (pos + strlen > rb->size) {//判断我们写的字节数是否大于整个buffer长度
        //cout<<"进入循环: "<<endl;
        // 目的地址 源地址 拷贝多少字节
        memcpy(rb->buff + pos, buf, rb->size - pos);//将我们的内容直接拷贝到偏移位置
        buf += (rb->size - pos); //移动到剩下没有拷贝完的位置
        strlen -= rb->size - pos;  //计算剩下的空间大小。
        pos = 0;//写索引位置更新为开头位置
        flag = 1;
    }
 
    //拷贝剩下的空间
    memcpy(rb->buff + pos, buf, strlen);//将多出来的长度的内容搬到基址开始，从我们的buf中继续写过来，实现循环
    // ???? 写索引 = 写指针 % 缓冲区长度？？？
    rb->wrId = pos + strlen; //移动我们的写指针
    rb->wrId = rb->wrId & (rb->size - 1);//???
 
    /*cout << "rb->wrId: " << rb->wrId << endl;
    cout << "rb->rdId: " << rb->rdId << endl;*/
    if (rb->rdId <= rb->wrId) {// 如果读索引小于等于写索引
 
        /*cout << "-----empty_space------" << empty_space << endl;
        cout << "-----tlen------" << tlen << endl;*/
        if (tlen >= empty_space) {//写入数据大于剩余
            rb->wptr = rb->wrId + rb->size;
            rb->rptr = rb->wrId;
            rb->rdId = rb->rptr & (rb->size - 1);
        }
        else {
            rb->rptr = rb->rdId;
            rb->wptr = rb->wrId;
        }
 
    }
    else {
        if (tlen > empty_space) {
            rb->wptr = rb->wrId;
            rb->rptr = rb->rdId;
            rb->rptr += (tlen - empty_space);
            rb->rdId = rb->rptr & (rb->size - 1);
        }
        else {
            rb->rptr = rb->rdId;
            rb->wptr = rb->wrId;
        }
        /*cout << "rb->wptr: " << rb->wptr << endl;
        cout << "rb->rptr: " << rb->rptr << endl;*/
    }
}
 
int read(ringbuff* rb, char* srcbuff, unsigned int len) {
    unsigned int pos = rb->rdId;
    unsigned int tmpPos = pos;//记录偏移位置
    unsigned int tlen = len;
    int flag = 0;
    int data = rb_data_size(rb);
 
    // empty buffer 报错！！
    if (!rb_data_size(rb)) {
        cout << "empty buffer" << endl;
        return 0;
    }
 
    if (len > rb_data_size(rb)) {
        len = rb_data_size(rb);
        cout << "已超出缓冲区大小，只可读取" << len << "个字节" << endl;
    }
 
    while (pos + len > rb->size) {
        memcpy(srcbuff, rb->buff + pos, rb->size - pos);
        srcbuff += (rb->size - pos);
        len -= (rb->size - pos);
        pos = 0;
        flag = 1;
    }
    memcpy(srcbuff, rb->buff + pos, len);
    rb->rdId = pos + len;
    rb->rdId = rb->rdId & (rb->size - 1);
    rb->wptr = rb->wrId;
    rb->rptr = rb->rdId;
    /*rb->wptr = rb->wrId + rb->size;
    rb->rptr = rb->rdId + rb->size;*/
}
 
void display(ringbuff* rb) {
    for (int i = 0; i < rb->size; i++) {
        cout << rb->buff[i];
    }
    cout << endl;
}
 
void readprint(ringbuff* rb, int len) {
    //01234567
    //89ABCDEF
    cout << endl;
    char buff[20] = "";
    read(rb, buff, len);
    int i = 0;
    cout << "读出：";
    while (buff[i] != '\0') {
        cout << buff[i++];
    }
    cout << endl;
    cout << "read_index: " << rb->rdId << endl;
    cout << "write_index: " << rb->wrId << endl;
    cout << "rptr = " << rb->rptr << endl;
    cout << "wptr = " << rb->wptr << endl;
    cout << "rb_state_get: " << rb_state_get(rb) << endl;
    cout << "rb_data_size: " << rb_data_size(rb) << endl;
    cout << "rb_free_size: " << rb_free_size(rb) << endl;
    cout << endl;
}
 
void writeprint(ringbuff* rb, char* p, int len) {
    //检验传入参数并顺序打印字符
    cout << "写入长度为len = " << len - 1 << "个字符： ";
    for (int i = 0; i < len - 1; i++) {
        cout << *(p + i);
        //cout << p[i];
    }
    cout << endl;

    write(rb, p, len - 1);//向
    display(rb); 
    cout << "read_index: " << rb->rdId << endl;
    cout << "write_index: " << rb->wrId << endl;
    cout << "rptr = " << rb->rptr << endl;
    cout << "wptr = " << rb->wptr << endl;
    cout << "rb_state_get: " << rb_state_get(rb) << endl;
    cout << "rb_data_size: " << rb_data_size(rb) << endl;
    cout << "rb_free_size: " << rb_free_size(rb) << endl;
    cout << endl;
}
 
int main() {
    ringbuff* rb = (ringbuff*)malloc(sizeof(ringbuff));
    char init_str[8] = "0000000";//栈空间的？
    int size = sizeof(init_str);
    Init(rb, init_str, size);
    //可以封装在初始化函数中。
 
    //char p[] = "123456789A";
    char p[] = "123456789A12345678";
    //char p[] = "12345678";
    int len = sizeof(p) / sizeof(char);//len 实际上是19
    //可以改成int len = strlen(p);
    writeprint(rb, p, len);
    readprint(rb, 7);
    readprint(rb, 9);
 
    char p1[] = "HEHEDA";
    len = sizeof(p1) / sizeof(char);
    writeprint(rb, p1, len);
 
    char p2[] = "Tom";
    len = sizeof(p2) / sizeof(char);
    writeprint(rb, p2, len);
 
    char p3[] = "abcdefgh";
    len = sizeof(p3) / sizeof(char);
    writeprint(rb, p3, len);
    readprint(rb, 6);
    readprint(rb, 3);
 
    char p4[] = "abcdefgh";
    len = sizeof(p4) / sizeof(char);
    writeprint(rb, p4, len);
 
    char p5[] = "kaixinma";
    len = sizeof(p5) / sizeof(char);
    writeprint(rb, p5, len);
    readprint(rb, 6);
 
    char p6[] = "handou";
    len = sizeof(p6) / sizeof(char);
    writeprint(rb, p6, len);
    readprint(rb, 6);
 
    char p7[] = "xiaohua";
    len = sizeof(p7) / sizeof(char);
    writeprint(rb, p7, len);
 
    char p8[] = "houlai";
    len = sizeof(p8) / sizeof(char);
    writeprint(rb, p8, len);
 
    char p9[] = "small";
    len = sizeof(p9) / sizeof(char);
    writeprint(rb, p9, len);
 
    char p10[] = "bigboy";
    len = sizeof(p10) / sizeof(char);
    writeprint(rb, p10, len);
 
    char p11[] = "yaoguai";
    len = sizeof(p11) / sizeof(char);
    writeprint(rb, p11, len);
 
    char p12[] = "halemu";
    len = sizeof(p12) / sizeof(char);
    writeprint(rb, p12, len);
 
    readprint(rb, 7);
 
    char p13[] = "kabola";
    len = sizeof(p13) / sizeof(char);
    writeprint(rb, p13, len);
 
    char p14[] = "skuraxi";
    len = sizeof(p14) / sizeof(char);
    writeprint(rb, p14, len);
 
    char p15[] = "xiaola";
    len = sizeof(p15) / sizeof(char);
    writeprint(rb, p15, len);
 
    readprint(rb, 7);
 
    char p16[] = "bobonihao";
    len = sizeof(p16) / sizeof(char);
    writeprint(rb, p16, len);
 
    char p17[] = "sha";
    len = sizeof(p17) / sizeof(char);
    writeprint(rb, p17, len);
    readprint(rb, 6);
 
    char p18[] = "guale";
    len = sizeof(p18) / sizeof(char);
    writeprint(rb, p18, len);
    readprint(rb, 8);
 
    char p19[] = "chaoshan";
    len = sizeof(p19) / sizeof(char);
    writeprint(rb, p19, len);
 
    char p20[] = "huabao";
    len = sizeof(p20) / sizeof(char);
    writeprint(rb, p20, len);
 
    readprint(rb, 4);
    readprint(rb, 1);
 
    char p21[] = "heheda";
    len = sizeof(p21) / sizeof(char);
    writeprint(rb, p21, len);
    readprint(rb, 4);
 
    char p22[] = "j";
    len = sizeof(p22) / sizeof(char);
    writeprint(rb, p22, len);
 
    readprint(rb, 4);
    readprint(rb, 4);
 
    char p23[] = "cokele";
    len = sizeof(p23) / sizeof(char);
    writeprint(rb, p23, len);
 
    char p24[] = "rp";
    len = sizeof(p24) / sizeof(char);
    writeprint(rb, p24, len);
    readprint(rb, 1);
 
    char p25[] = "oz";
    len = sizeof(p25) / sizeof(char);
    writeprint(rb, p25, len);
    readprint(rb, 8);
}
