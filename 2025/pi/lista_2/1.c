#include <stdio.h>
#include <stdlib.h>

double galoes_para_litros(double galoes) {
  double taxa_de_conversao = 3.7854;

  return galoes * taxa_de_conversao;
}

int main() {
  double galoes;

  scanf("%lf", &galoes);

  printf("%0.4lf\n", galoes_para_litros(galoes));

  exit(EXIT_SUCCESS);
}
