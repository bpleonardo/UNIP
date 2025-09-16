#include <stdio.h>
#include <string.h>

float leia_int(char* prompt) {
    printf("%s", prompt);

    int resultado;
    scanf("%d", &resultado);

    return resultado;
}

int main()
{
    int resultado[10];
    
    int n = leia_int("Digite um número: ");
    
    for (int i; i < 10; i++) {
        resultado[i] = (i + 1) * n;
    }
    
    for (int i; i < 10; i++) {
        printf("%d * %d = %d\n", n, i + 1, resultado[i]);
    }
    

    return 0;
}
