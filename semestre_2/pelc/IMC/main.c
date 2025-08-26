#include <stdio.h>

float leia_float(char* prompt) {
    printf(prompt);

    float resultado;
    scanf("%f", &resultado);

    return resultado;
}

double calcula_imc(float peso, float altura) {
    altura = altura / 100;

    return peso / (altura * altura);
}

char* classifica_imc(double imc) {
    // https://abeso.org.br/wp-content/uploads/2019/12/Diretrizes-Download-Diretrizes-Brasileiras-de-Obesidade-2016.pdf
    // Tabela 04 - Página 16.
    if (imc < 18.5) {
        return "Você está magro.\n";
    } else if (imc < 25) {
        return "Você está eutrófico (peso normal).\n";
    } else if (imc < 30) {
        return "Você está pré-obeso.\n";
    } else if (imc < 35) {
        return "Você está com obesidade grau 1.\n";
    } else if (imc < 40) {
        return "Você está com obesidade grau 2.\n";
    } else {
        return "Você está com obesidade grave (grau 3).\n";
    }
}

int main() {
    float peso = leia_float("Digite seu peso (kg): ");
    float altura = leia_float("Digite sua altura (cm): ");

    double imc = calcula_imc(peso, altura);

    char* classificacao = classifica_imc(imc);

    printf(classificacao);

    return 0;
}
