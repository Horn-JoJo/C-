#include <iostream>
using namespace std;

//memmove 用于拷贝字节，如果目标区域和源区域有重叠的话，memmove 能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中，但复制后源内容会被更改。但是当目标区域与源区域没有重叠则和memcpy函数相同

void* myMemmove(void* dest, const void* src, size_t size) {
    char* psrc, *pdst;
    
    if (NULL == dest || NULL == src) {
        return NULL;
    }

    if (dest < src) {
        //从前往后进行拷贝
        pdst = (char*)dest, psrc = (char*)src;
        while (size--) {
            *pdst++ = *psrc++;
        }
    } else {
        pdst = (char*)dest + size - 1, psrc = (char*)src + size - 1;
        while (size--) {
            *pdst-- = *psrc--;
        }
    }

    return dest;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    myMemmove(arr + 2, arr, 16);//拷贝16个字节，也就是4个连续的整形数据
    for (auto& x : arr) cout << x << endl;// 1 2 1 2 3 4 5 6 7 8 9 10
    myMemmove(arr, arr + 2, 16);//拷贝16个字节，也就是4个连续的整形数据
    for (auto& x : arr) cout << x << endl;// 1 2 3 4 3 4 5 6 7 8 9 10
    return 0;
}
