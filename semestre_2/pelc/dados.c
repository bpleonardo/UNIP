#include <stdio.h>

#include <string.h>

void leia_string(char* prompt, char texto[], int tamanho) {
    printf("%s", prompt);

    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

int main() {
    char nome[34];
    leia_string("Insira seu nome: ", nome, 33);

    char sobrenome[34];
    leia_string("Insira seu sobrenome: ", sobrenome, 33);

    char data_nascimento[12];
    leia_string("Insira sua data de nascimento: ", data_nascimento, 12);

    // Um email pode ter no máximo 320 caracteres.
    // Fonte: https://www.rfc-editor.org/rfc/rfc3696 (3. Restrictions on email
    // addresses)
    char email[322];
    leia_string("Insira seu email: ", email, 321);

    char celular[16];
    leia_string("Insira seu telefone no formato internacional: ", celular, 15);

    printf(
        "\nNome: %s\nSobrenome: %s\nData de nascimento: %s\nEmail: %s\nCelular: "
        "%s\n",
        nome, sobrenome, data_nascimento, email, celular);

    return 0;
}
