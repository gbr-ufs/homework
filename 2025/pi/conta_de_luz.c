#include <stdio.h>

double descontar(double valor, double desconto) {
  desconto *= valor;

  return valor - desconto;
}

int main() {
  // Entrada.
  double consumo;
  // Saída.
  double valor = 1.5, desconto = 15.0 / 100.0,
         valor_descontado = descontar(valor, desconto);

  scanf("%lf", &consumo);
  printf("Valor a ser pago: R$ %0.2lf reais\n", valor * consumo);
  printf("Valor a ser pago com desconto: R$ %0.2lf reais\n",
         valor_descontado * consumo);

  return 0;
}
