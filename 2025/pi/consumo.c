#include <stdio.h>

int main() {
  // Entrada.
  long distancia_total;
  double combustivel_gasto;
  // Saída.
  double consumo_medio;

  scanf("%ld %lf", &distancia_total, &combustivel_gasto);
  consumo_medio = distancia_total / combustivel_gasto;
  printf("%0.3lf km/l\n", consumo_medio);

  return 0;
}
