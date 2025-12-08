#include <stdio.h>
#include <stdlib.h>

int main() {
  float notas[3];
  float soma = 0.0;
  float media = 0.0;
  char *resultado;

  for (int i = 0; i < 3; i++) {
    scanf("%f", &notas[i]);
    soma += notas[i];
  }

  media = soma / 3.0;

  if (media <= 10.0 && media >= 7.0) {
    resultado = "Aprovado";
  } else if (media < 7.0 && media >= 3.0) {
    resultado = "Prova Final";
  } else {
    resultado = "Reprovado";
  }

  printf("%s\n", resultado);

  exit(EXIT_SUCCESS);
}
