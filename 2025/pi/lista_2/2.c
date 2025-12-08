#include <stdio.h>
#include <stdlib.h>

int main() {
  int numeros[3];

  for (int i = 0; i < 3; i++) {
    scanf("%d", &numeros[i]);
  }

  for (int i = 3 - 1; i >= 0; i--) {
    printf("%d\n", numeros[i]);
  }

  exit(EXIT_SUCCESS);
}
