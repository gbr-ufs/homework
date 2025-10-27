#include <stdio.h>

int main() {
  int numero, multiplo;

  scanf("%d", &numero);

  for (int i = 1; i <= 9; i++) {
    multiplo = numero * i;
    printf("%d X %d = %d\n", numero, i, multiplo);
  }

  return 0;
}
