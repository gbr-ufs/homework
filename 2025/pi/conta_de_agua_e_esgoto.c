#include <stdio.h>

int main() {
  // Entrada.
  // Metros cúbicos e litro.
  double agua_consumida, custo;
  // Saída.
  double valor_agua, valor_esgoto, valor_total;

  scanf("%lf %lf", &agua_consumida, &custo);
  // Conversão de metros cúbicos para litros.
  agua_consumida *= 1000.0;
  valor_agua = agua_consumida * custo;
  valor_esgoto = valor_agua * (80.0 / 100.0);
  valor_total = valor_agua + valor_esgoto;
  printf("%0.2lf\n", valor_agua);
  printf("%0.2lf\n", valor_esgoto);
  printf("%0.2lf\n", valor_total);

  return 0;
}
