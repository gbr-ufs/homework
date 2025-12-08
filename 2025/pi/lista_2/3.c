#include <stdio.h>
#include <stdlib.h>

double peso_terra_para_peso_lua(double peso) {
  double taxa_de_conversao = 17.0 / 100.0;

  return peso * taxa_de_conversao;
}

int main() {
  double peso;

  scanf("%lf", &peso);

  printf("%lf\n", peso_terra_para_peso_lua(peso));

  exit(EXIT_SUCCESS);
}
