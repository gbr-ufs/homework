#include <stdio.h>

double potencia(double x, double z) {
  double resultado = x;

  if (z == 0) {
    return 1.0;
  }

  for (int i = 2; i <= z; i++) {
    resultado *= x;
  }

  return resultado;
}

int main() {
  double x;
  double z;
  double pot;

  scanf("%lf", &x);
  scanf("%lf", &z);

  pot = potencia(x, z);

  printf("%lf\n", pot);

  return 0;
}
