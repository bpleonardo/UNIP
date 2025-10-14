#include <stdio.h>
#include <stdlib.h>

int leia_int(char* prompt);

int main() {
    int t = leia_int("Insira o tamanho: ");

    if (t > 0) {
        int *ptr = (int*) malloc(t * sizeof(int));

        for (int i = 0; i < t; i++) {
            printf("Insira o valor da posição %d: ", i);
            scanf("%d", &ptr[i]);
        }

        int soma = 0;
        for (int i = 0; i < t; i++) {
            soma += ptr[i];
        }

        printf("A soma dos valores informados é %d", soma);

        free(ptr);
        ptr = NULL;
    } else {
        printf("O valor informado deve ser maior que 0.");
    }

    return 0;
}

int leia_int(char* prompt) {
    printf("%s", prompt);

    int resultado;
    scanf("%d", &resultado);

    return resultado;
}
