#include <stdio.h>

int main() {
  float notas[10];
  float media;
  float soma;

  for (int i = 0; i < 10; i++) {
    scanf("%f", &notas[i]);
    soma += notas[i];
  }

  media = soma / 10.0;

  for (int i = 0; i < 10; i++) {
    if (notas[i] > media) {
      printf("índice: %d nota: %f\n", i, notas[i]);
    }
  }

  return 0;
}
