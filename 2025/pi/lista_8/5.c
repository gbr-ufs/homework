#include <stdio.h>

double potencia_de_dois(double n, double acc) {
  if (n == 1) {
    return acc;
  }

  if (n == 0) {
    return 1.0;
  }

  return potencia_de_dois(n - 1, acc * 2.0);
}

int main() {
  double n;
  double pot;

  scanf("%lf", &n);

  pot = potencia_de_dois(n, 2.0);

  printf("%lf\n", pot);

  return 0;
}
