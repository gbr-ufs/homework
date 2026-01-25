#include <stdio.h>

double potencia_de_dois(double n) {
  double partida = 2.0;
  double resultado = partida;

  if (n == 0) {
    return 1.0;
  }

  for (int i = 2; i <= n; i++) {
    resultado *= partida;
  }

  return resultado;
}

int main() {
  double n;
  double pot;

  scanf("%lf", &n);

  pot = potencia_de_dois(n);

  printf("%lf\n", pot);

  return 0;
}
