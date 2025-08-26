#include <stdio.h>

int main() {
    float peso, altura;

    printf("Digite seu peso (kg): ");
    scanf("%f", &peso);

    printf("Digite sua altura (cm): ");
    scanf("%f", &altura);

    altura = altura / 100;

    double imc = peso / (altura * altura);

    // https://abeso.org.br/wp-content/uploads/2019/12/Diretrizes-Download-Diretrizes-Brasileiras-de-Obesidade-2016.pdf
    // Tabela 04 - Página 16.
    if (imc < 18.5) {
        printf("Você está magro.");
    } else if (imc < 25) {
        printf("Você está eutrófico (peso normal).");
    } else if (imc < 30) {
        printf("Você está pré-obeso.");
    } else if (imc < 35) {
        printf("Você está com obesidade grau 1.");
    } else if (imc < 40) {
        printf("Você está com obesidade grau 2.");
    } else {
        printf("Você está com obesidade grave (grau 3).");
    }

    printf("\n");

    return 0;
}