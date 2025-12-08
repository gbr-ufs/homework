#include <stdio.h>
#include <stdlib.h>

int main() {
  int valor;
  int tmp;

  scanf("%d", &valor);

  if (valor == 0) {
    printf("%d\n", valor);
    exit(EXIT_SUCCESS);
  }

  scanf("%d", &tmp);

  while (tmp != 0) {
    if (tmp > valor) {
      valor = tmp;
    }

    scanf("%d", &tmp);
  }

  printf("%d\n", valor);

  exit(EXIT_SUCCESS);
}
