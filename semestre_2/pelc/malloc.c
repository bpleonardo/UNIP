#include <stdio.h>
#include <stdlib.h>

#define null 0

int leia_int(char* prompt);

int main() {
    int t = leia_int("Insira o tamanho: ");

    int *ptr = (int*) malloc(t * sizeof(int));
    printf("%p", (void*)ptr);

    free(ptr);
    ptr = null;

    return 0;
}

int leia_int(char* prompt) {
    printf("%s", prompt);

    int resultado;
    scanf("%d", &resultado);

    return resultado;
}
