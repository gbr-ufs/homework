#include <stdio.h>
#include <stdlib.h>

double imposto_de_renda(double salario) {
  double salario_menos_isento = salario - 2000.0;
  double acima_de_3000 = salario - 3000.0;
  double acima_de_4500 = salario - 4500.0;
  double resultado = 0.0;

  if (acima_de_4500 > 0.0) {
    resultado += acima_de_4500 * (28.0 / 100.0);
  } else {
    acima_de_4500 = 0.0;
  }

  if (acima_de_3000 > 0.0) {
    resultado += (acima_de_3000 - acima_de_4500) * (18.0 / 100.0);
  } else {
    acima_de_3000 = 0.0;
  }

  if (salario_menos_isento > 0.0) {
    resultado += (salario_menos_isento - acima_de_3000) * (8.0 / 100.0);
  }

  return resultado;
}

int main() {
  double salario;
  double resultado;

  scanf("%lf", &salario);

  resultado = imposto_de_renda(salario);

  if (resultado != 0.0) {
    printf("R$ %0.2lf\n", resultado);
  } else {
    printf("Isento\n");
  }

  exit(EXIT_SUCCESS);
}
