#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

float leia_float(char* prompt);
int leia_int(char* prompt);
void leia_string(char* prompt, char* buffer, int tamanho);

int main() {
    Pessoa p;
  
    leia_string("Insira nome: ", p.nome, 50);
    p.idade = leia_int("Insira idade: ");
    p.altura = leia_float("Insira altura: ");

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f\n", p.altura);
    
    return 0;
}

float leia_float(char* prompt) {
    printf("%s", prompt);

    float resultado;
    scanf("%f", &resultado);

    return resultado;
}

int leia_int(char* prompt) {
    printf("%s", prompt);

    int resultado;
    scanf("%d", &resultado);

    return resultado;
}

void leia_string(char* prompt, char* buffer, int tamanho) {
    printf("%s", prompt);

    if (fgets(buffer, tamanho, stdin) != 0) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}
