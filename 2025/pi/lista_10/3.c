#include <stdio.h>
#include <string.h>

struct professor {
  long matricula;
  char nome[51];
  char departamento[11];
};

int main() {
  struct professor professores[100];

  for (int i = 0; i < 100; i++) {
    scanf("%ld", &professores[i].matricula);
    scanf("%50s", professores[i].nome);
    scanf("%50s", professores[i].departamento);
  }

  for (int i = 0; i < 100; i++) {
    if (strcmp(professores[i].departamento, "DCOMP") == 0) {
      printf("Matrícula: %ld Nome: %s\n", professores[i].matricula,
             professores[i].nome);
    }
  }

  return 0;
}
