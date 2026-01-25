#include <stdio.h>

double potencia(double x, double z, double original) {

  if (z == 1) {
    return x;
  }

  if (z == 0) {
    return 1.0;
  }

  return potencia(original * x, z - 1, original);
}

int main() {
  double x;
  double z;
  double pot;

  scanf("%lf", &x);
  scanf("%lf", &z);

  pot = potencia(x, z, x);

  printf("%lf\n", pot);

  return 0;
}
