#include <stdio.h>
#include <stdlib.h>

int main() {
  long valores[10];
  long ultimo;
  long contagem = 1;

  for (int i = 0; i < 10; i++) {
    scanf("%ld", &valores[i]);
  }

  ultimo = valores[9];

  for (int i = 0; i < 9; i++) {
    if (valores[i] == ultimo) {
      contagem++;
    }
  }

  printf("O numero %ld apareceu %ld vezes\n", ultimo, contagem);

  exit(EXIT_SUCCESS);
}
