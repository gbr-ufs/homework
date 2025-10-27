#include <stdio.h>

double taxar(double valor, double taxa) {
  taxa *= valor;

  return valor + taxa;
}

int intervalo(long inicio, long valor, long fim) {
  if (valor >= inicio && valor <= fim) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  // Entrada.
  long energia_consumida;
  // Saída.
  // Até 99 KWh.
  double valor_1 = 1.35;
  // De 100 até 299 KWh.
  long intervalo_2_inicio = 100, intervalo_2_fim = 299;
  double valor_2 = 1.55;
  // De 300 até 574 KWh.
  long intervalo_3_inicio = 300, intervalo_3_fim = 574;
  double valor_3 = 1.75;
  // Maior ou igual a 575 KWh.
  double valor_4 = 2.15;
  double taxa = 10.0 / 100.0;
  double conta = 35.0;
  double valor_impresso;

  scanf("%ld", &energia_consumida);
  if (energia_consumida <= 99) {
    conta = valor_1 * energia_consumida;
    valor_impresso = valor_1;
  } else if (intervalo(intervalo_2_inicio, energia_consumida,
                       intervalo_2_fim)) {
    conta = valor_2 * energia_consumida;
    valor_impresso = valor_2;
  } else if (intervalo(intervalo_3_inicio, energia_consumida,
                       intervalo_3_fim)) {
    conta = valor_3 * energia_consumida;
    valor_impresso = valor_3;
    if (energia_consumida > intervalo_3_inicio) {
      conta = taxar(conta, taxa);
    }
  } else {
    conta = taxar(valor_4 * energia_consumida, taxa);
    valor_impresso = valor_4;
  }

  if (conta < 35.0) {
    conta = 35.0;
  }

  printf("%0.2lf\n", conta);
  printf("%0.2lf\n", valor_impresso);

  return 0;
}
