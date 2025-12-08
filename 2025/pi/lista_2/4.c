#include <stdio.h>
#include <stdlib.h>

int main() {
  int numeros[3];
  int soma = 0;
  float media = 0.0;

  for (int i = 0; i < 3; i++) {
    scanf("%d", &numeros[i]);
    soma += numeros[i];
  }

  media = (float)soma / 3.0;

  printf("%0.2f\n", media);

  exit(EXIT_SUCCESS);
}
