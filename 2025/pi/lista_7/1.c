#include <stdio.h>

int e_par(int numero) { return numero % 2 == 0; }

int main() {
  int numero;
  char *saida;

  scanf("%d", &numero);

  if (e_par(numero)) {
    saida = "par";
  } else {
    saida = "impar";
  }

  printf("%s\n", saida);

  return 0;
}
