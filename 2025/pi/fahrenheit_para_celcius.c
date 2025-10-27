#include <stdio.h>

int main() {
  // Entrada.
  double fahrenheit;
  // Saída.
  double celsius;

  scanf("%lf", &fahrenheit);
  celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
  printf("%0.2lf\n", celsius);

  return 0;
}
