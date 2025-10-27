#include <stdio.h>

int main() {
  // Entrada.
  long numero;
  // Saída.
  int unidade;

  scanf("%ld", &numero);
  unidade = numero % 10;
  printf("%d\n", unidade);

  return 0;
}
