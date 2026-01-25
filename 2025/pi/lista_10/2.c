#include <stdio.h>

struct cliente {
  long numero_da_conta;
  char nome[257];
  double saldo;
};

int main() {
  struct cliente clientes[15];
  double saldo_total = 0.0;

  for (int i = 0; i < 15; i++) {
    scanf("%ld", &clientes[i].numero_da_conta);
    scanf("%256s", clientes[i].nome);
    scanf("%lf", &clientes[i].saldo);

    while (clientes[i].saldo < 0.0) {
      printf("2: Saldo inválido, digite novamente\n");
      scanf("%lf", &clientes[i].saldo);
    }

    saldo_total += clientes[i].saldo;
  }

  printf("Saldo total do banco: R$ %.2lf\n", saldo_total);

  return 0;
}
