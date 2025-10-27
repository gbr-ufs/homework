#include <stdio.h>

int main() {
  // Entrada.
  long valor;
  // Saída.
  long notas_de_100 = 0, notas_de_50 = 0, notas_de_20 = 0, notas_de_10 = 0,
       notas_de_5 = 0, notas_de_2 = 0, notas_de_1 = 0;

  scanf("%ld", &valor);
  printf("%ld\n", valor);
  notas_de_100 = valor / 100;
  valor %= 100;
  notas_de_50 = valor / 50;
  valor %= 50;
  notas_de_20 = valor / 20;
  valor %= 20;
  notas_de_10 = valor / 10;
  valor %= 10;
  notas_de_5 = valor / 5;
  valor %= 5;
  notas_de_2 = valor / 2;
  valor %= 2;
  notas_de_1 = valor;
  printf("%ld nota(s) de R$ 100,00\n", notas_de_100);
  printf("%ld nota(s) de R$ 50,00\n", notas_de_50);
  printf("%ld nota(s) de R$ 20,00\n", notas_de_20);
  printf("%ld nota(s) de R$ 10,00\n", notas_de_10);
  printf("%ld nota(s) de R$ 5,00\n", notas_de_5);
  printf("%ld nota(s) de R$ 2,00\n", notas_de_2);
  printf("%ld nota(s) de R$ 1,00\n", notas_de_1);

  return 0;
}
