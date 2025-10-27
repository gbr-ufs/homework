#include <stdio.h>

int main() {
  // Entrada.
  double primeiro, segundo;
  // Saída.
  double soma, subtracao, multiplicacao, divisao;

  scanf("%lf %lf", &primeiro, &segundo);
  soma = primeiro + segundo;
  subtracao = primeiro - segundo;
  multiplicacao = primeiro * segundo;
  divisao = primeiro / segundo;

  printf("%0.2lf\n", soma);
  printf("%0.2lf\n", subtracao);
  printf("%0.2lf\n", multiplicacao);
  printf("%0.2lf\n", divisao);

  return 0;
}
