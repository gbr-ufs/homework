#include <stdio.h>
#include <stdlib.h>

int main() {
  int primeiro, segundo;
  int contador = 0;

  scanf("%d %d", &primeiro, &segundo);

  for (int i = 49; i != 0; i--) {
    if (i % primeiro == 0 && i % segundo == 0) {
      contador++;
    }
  }

  printf("%d\n", contador);

  exit(EXIT_SUCCESS);
}
