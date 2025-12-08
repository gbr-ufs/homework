#include <stdio.h>
#include <stdlib.h>

int main() {
  long valores[101];
  long ultimo;

  for (int i = 0; i < 101; i++) {
    scanf("%ld", &valores[i]);
  }

  ultimo = valores[100];

  for (int i = 0; i < 100; i++) {
    if (valores[i] == ultimo) {
      printf("%d\n", i);
    }
  }

  exit(EXIT_SUCCESS);
}
