#include <stdio.h>

int main() {
  int numeros[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &numeros[i]);
  }

  for (int i = 0; i < 10; i++) {
    if (numeros[i] % 2 == 0) {
      printf("índice: %d número: %d\n", i, numeros[i]);
    }
  }

  return 0;
}
