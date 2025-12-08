#include <stdio.h>
#include <stdlib.h>

double custo_energia(double salario_minimo) { return salario_minimo / 5.0; }

double custo_com_desconto(double custo, double desconto) {
  double valor_descontado = custo * desconto;

  return custo - valor_descontado;
}

int main() {
  double salario_minimo;
  double kw;

  scanf("%lf %lf", &salario_minimo, &kw);
  double custo = custo_energia(salario_minimo);

  printf("R$ %0.2lf\n", custo);
  printf("R$ %0.2lf\n", custo * kw);
  printf("R$ %0.2lf\n", custo_com_desconto(custo, (15.0 / 100.0)) * kw);

  exit(EXIT_SUCCESS);
}
