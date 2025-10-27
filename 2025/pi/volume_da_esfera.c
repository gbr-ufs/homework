#include <math.h>
#include <stdio.h>

int main() {
  const double PI = 3.1416;
  // Entrada.
  double raio;
  // Saída.
  double volume;

  scanf("%lf", &raio);
  volume = (4 * PI * pow(raio, 3)) / 3;
  printf("%0.2lf\n", volume);

  return 0;
}
