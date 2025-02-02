#include <string.h> // For strcmp
#include <stdio.h>
#include <stdlib.h>

int CmpString(const void *p1, const void *p2) {
    const char *str1 = *(const char **)p1; // Cast and dereference to get the actual string
    const char *str2 = *(const char **)p2; // Cast and dereference to get the actual string

    return strcmp(str1, str2); // Use strcmp to compare the strings
}

int main() {  
    char *arrStr[] = {"daa", "cbab", "bbbb", "bababa", "ccccc", "aaaa"};
    int arrStrLen = sizeof(arrStr) / sizeof(char *);
    qsort(arrStr, arrStrLen, sizeof(char *), CmpString);
    printf("Sorted elements in array are: ");
    for (int i = 0; i<arrStrLen; i++) {
        printf(" %s", arrStr[i]);
    }
    return 0;
}