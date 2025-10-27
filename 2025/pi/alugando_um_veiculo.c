#include <stdio.h>

int main() {
  // Entrada.
  long dias, quilometragem;
  // Saída.
  double valor_pago = 90.0;
  double limite_diario = 100.0;

  scanf("%ld %ld", &dias, &quilometragem);
  valor_pago *= dias;
  limite_diario *= dias;

  if (quilometragem > limite_diario) {
    valor_pago += (quilometragem - limite_diario) * 12.0;
  }

  printf("%0.2lf\n", valor_pago);

  return 0;
}
