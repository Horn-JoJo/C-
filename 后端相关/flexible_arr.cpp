#include <stdio.h>
#include <stdlib.h>

typedef struct FlexArrayStruct {
    int length;
    int data[];
}FlexArray;

int main() {
    int arrLength = 10;
    //实例化的包含柔性数组的结构体大小需要手动计算大小。不能用sizeof来计算！！！
    FlexArray* myArray = (FlexArray*)malloc(sizeof(FlexArray) + arrLength * sizeof (int));
    if (NULL != myArray) {
        myArray ->length = arrLength;
        for (int i = 0; i < myArray->length;  i++) {
            myArray->data[i] = i * 10;
        }
    }

    for (int i = 0; i < myArray->length;  i++) {
        printf("myArray[%d] = %d\n", i, myArray->data[i]);
    }

    free(myArray);
    myArray = NULL;

    return 0;
}

/*
柔性数组特点：
    1. 未实例化的含有柔性数组的结构体大小=除了柔性数组的其他字节大小之和。如果除了柔性数组成员外，没有其他成员，则sizeof(结构体) = 0.
    2. 实例化柔性数组对应的大小需要手动计算（包含类的部分+柔性数组的部分)，而不能用sizeof来计算。
    3. 柔性数组只能用于动态分配，因为需要运行时分配额外的内存来存储数组数据。在栈上或静态内存分配中，柔性数组是不允许的。
*/
