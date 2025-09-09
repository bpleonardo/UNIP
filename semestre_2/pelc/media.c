#include <stdio.h>

float leia_float(char* prompt) {
    printf("%s", prompt);

    float resultado;
    scanf("%f", &resultado);

    return resultado;
}

int main() {
    printf("Calculadora de média.\n");
    
    float soma;
    int qnt = 0;
    float num;
    
    do {
        num = leia_float("Digite a nota ou -1 para sair: ");
        if (num > 0) {
            soma += num;
            qnt++;
        }
    } while (num > 0);
    
    printf("A média das %d notas é: %f.", qnt, (soma / qnt));

    return 0;
}
