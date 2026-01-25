#include <stdio.h>

double area(double base, double altura) { return (base * altura) / 2.0; }

int main() {
  double base;
  double altura;
  double ar;

  scanf("%lf", &base);
  scanf("%lf", &altura);

  ar = area(base, altura);

  printf("%lf\n", ar);

  return 0;
}
