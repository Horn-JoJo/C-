#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* mystrcpy(char* strDest, const char* strSrc) {
    if (strDest == NULL || strSrc == NULL) {
        puts("Invalid argument");
        return "null s";
    }

    char* strDestCopy = strDest;
    while ((*strDest++ = *strSrc++) != '\0');

    return strDestCopy;
}
int main() {
    char* dest = (char*)malloc(sizeof(char) * 10);
    memset(dest, 0, 10);
    char* src = "hello world!";
    printf("%s\n", mystrcpy(dest, src));
    return 0;
}
