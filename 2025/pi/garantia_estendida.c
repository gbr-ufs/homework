#include <stdio.h>

double taxar(double valor, double taxa) {
  taxa *= valor;

  return valor + taxa;
}

int main() {
  // Entrada.
  double valor;
  long anos;
  // Saída.
  double taxa_um_ano = 3.0 / 100.0, taxa_dois_anos = 5.0 / 100.0;
  double valor_com_garantia, valor_com_garantia_estendida;

  scanf("%lf %ld", &valor, &anos);
  valor_com_garantia = taxar(valor, taxa_um_ano);
  valor_com_garantia_estendida = taxar(valor, taxa_dois_anos);

  if (anos == 1) {
    printf("%0.2lf\n", valor_com_garantia);
  } else if (anos == 2) {
    printf("%0.2lf\n", valor_com_garantia_estendida);
  } else {
    printf("%0.2lf\n", valor);
  }

  return 0;
}
