#include <stdio.h>

int main() {
  const double PI = 3.14;
  // Entrada.
  double altura, raio;
  // Saída.
  double volume, area_base, area_lateral, area_total;

  scanf("%lf %lf", &altura, &raio);

  volume = PI * (raio * raio) * altura;
  area_base = PI * (raio * raio);
  area_lateral = 2 * PI * raio * altura;
  area_total = 2 * area_base + area_lateral;
  printf("%0.2lf\n%0.2lf\n", volume, area_total);

  return 0;
}
