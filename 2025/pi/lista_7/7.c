#include <stdio.h>

double somar_vetor(double *vetor, int n) {
  double soma = 0.0;

  for (int i = 0; i < n; i++) {
    soma += vetor[i];
  }

  return soma;
}

int main() {
  double vetor[4];
  double soma = 0.0;

  for (int i = 0; i < 4; i++) {
    scanf("%lf", &vetor[i]);
  }

  soma = somar_vetor(vetor, 4);

  printf("%lf\n", soma);

  return 0;
}
