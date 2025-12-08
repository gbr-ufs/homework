#include <stdio.h>
#include <stdlib.h>

double quantidade_de_salarios_minimos(double salario_minimo,
                                      double salario_funcionario) {
  return salario_funcionario / salario_minimo;
}

int main() {
  double salario_minimo;
  double salaio_funcionario;

  scanf("%lf", &salario_minimo);
  scanf("%lf", &salaio_funcionario);

  printf("%0.2lf\n",
         quantidade_de_salarios_minimos(salario_minimo, salario_minimo));

  exit(EXIT_SUCCESS);
}
