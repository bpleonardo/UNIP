#include <stdio.h>

int main() {
    int var = 10;
    int *ptr;
    ptr = &var;
    
    printf("var=%d[%p]\n\n", var, (void*)&var);
    printf("*ptr=%d[%p][%p]\n", *ptr, (void*)ptr, (void*)&ptr);
    return 0;
}
