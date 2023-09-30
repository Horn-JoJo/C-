#include <stdio.h>
#include <stdlib.h>

int main() {
    char* p = (char*)malloc(1);
    *p = 'c';

    char c = *p;

    printf("\n [%c]\n", c);

    return 0;
}
