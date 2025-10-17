#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(FILE* file) {
  int size;

  fseek(file, 0, SEEK_END);
  size = ftell(file);
  fseek(file, 0, SEEK_SET);

  return size;
}

int readFileUntilEof(FILE* file) {}

int main() {
  FILE* fp = fopen("parse.txt", "r");

  if (fp == NULL) {
    perror("Error parsing file");
    return 1;
  }

  int size = getFileSize(fp);

  char* buffer = (char*) malloc(size);

  for (int i = 0; i < size; i++) {
    char c = fgetc(fp);

    if (c == EOF) {
      perror("O arquivo atingiu EOF...");
      fclose(fp);
      free(buffer);
      return 1;
    };

    buffer[i] = c;
  }

  fclose(fp);
  fp = NULL;

  buffer[size] = '\0';

  printf("%s\n", buffer);

  free(buffer);
  buffer = NULL;

  return 0;
}
