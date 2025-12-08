#include <stdio.h>
#include <stdlib.h>

// Quem consome menos paga menos.
// Assinatura mensal de R$ 7, 10 m3 de água. Pago mesmo sem consumo.
// Acima de 10m3, cada m3 tem um valor diferente:
// - 11 a 30 -> R$ 1
// - 31 a 100 -> R$ 2
// - 101 em diante -> R 5
// consumo de 120 m3:
// - 7 reais da assinatura
// - 20 reais do intervalo 11 a 30
// - 140 reais do intervalo 31 a 100
// - 100 reais do intervalo 101 a 120
// dando 267 reais.

int valor_da_conta(int consumo) {
  int acima_de_100 = consumo - 100;
  int acima_de_30 = consumo - 30;
  int acima_de_10 = consumo - 10;
  int resultado = 7;

  if (acima_de_100 > 0) {
    resultado += acima_de_100 * 5;
  } else {
    acima_de_100 = 0;
  }

  if (acima_de_30 > 0) {
    resultado += (acima_de_30 - acima_de_100) * 2;
  } else {
    acima_de_30 = 0;
  }

  if (acima_de_10 > 0) {
    resultado += (acima_de_10 - acima_de_30);
  }

  return resultado;
}

int main() {
  int consumo;

  scanf("%d", &consumo);

  printf("%d\n", valor_da_conta(consumo));
  exit(EXIT_SUCCESS);
}
