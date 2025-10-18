#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerString(const char* prompt, char* buffer, int tamanho);
int obterTamanho(FILE* file);
char* lerArquivo(char* path);

int main() {
  char caminho[255];
  if (lerString("Insira o caminho do arquivo: ", caminho, 255) == 0) {
    perror("fgets");
    return 1;
  }

  char* content = lerArquivo(caminho);

  if (content == NULL) {
    perror("Erro ao ler arquivo");
    return 1;
  }

  printf("%s\n", content);

  free(content);
  content = NULL;

  while (1) {}

  return 0;
}

int lerString(const char* prompt, char* buffer, int tamanho) {
  printf("%s", prompt);

  if (fgets(buffer, tamanho, stdin) == NULL) { return 0; }

  buffer[strcspn(buffer, "\n")] = '\0';

  return 1;
}

int obterTamanho(FILE* file) {
  int before = ftell(file);

  fseek(file, 0, SEEK_END);

  int size = ftell(file);

  fseek(file, before, SEEK_SET);

  return size;
}

char* lerArquivo(char* path) {
  FILE* fp = fopen(path, "r");

  if (fp == NULL) return NULL;

  int size = obterTamanho(fp);

  char* buffer = malloc((size + 1) * sizeof(char)); // Deixar espaço para o \0
  buffer[size] = '\0';

  fread(buffer, sizeof(char), size, fp);

  fclose(fp);

  return buffer;
}
