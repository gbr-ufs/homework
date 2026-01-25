#include <stdio.h>

int main() {
  double valor_inflacao = 5.5 / 100.0;
  double salario_minimo = 900.0;
  double salarios[10];

  for (int i = 0; i < 10; i++) {
    if (i == 0) {
      salarios[i] = salario_minimo + (salario_minimo * valor_inflacao);
    } else {
      double salario_anterior = salarios[i - 1];
      salarios[i] = salario_anterior + (salario_anterior * valor_inflacao);
    }
  }

  for (int i = 0; i < 10; i++) {
    char *tempo;

    if (i == 0) {
      tempo = "ano";
    } else {
      tempo = "anos";
    }

    printf("Salário daqui a %d %s: R$ %.2lf\n", i + 1, tempo, salarios[i]);
  }

  return 0;
}
