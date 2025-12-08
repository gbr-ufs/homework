#include <stdio.h>
#include <stdlib.h>

double aumento(double salario, double taxa) { return salario * taxa; }

double novo_salario(double salario, double aumento) {
  return salario + aumento;
}

int main() {
  double salario;

  scanf("%lf", &salario);
  double extra = aumento(salario, (25.0 / 100.0));

  printf("R$ %0.2lf\n", salario);
  printf("R$ %0.2lf\n", extra);
  printf("R$ %0.2lf\n", novo_salario(salario, extra));

  exit(EXIT_SUCCESS);
}
