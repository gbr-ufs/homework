#include <stdio.h>
#include <stdlib.h>

int main() {
  int primeiro;
  int segundo;
  int terceiro;
  int resultado;

  scanf("%d %d %d", &primeiro, &segundo, &terceiro);

  if (primeiro > segundo && primeiro > terceiro) {
    resultado = primeiro;
  } else if (segundo > primeiro && segundo > terceiro) {
    resultado = segundo;
  } else if (terceiro > segundo && terceiro > primeiro) {
    resultado = terceiro;
    // Todos iguais.
  } else {
    resultado = primeiro;
  }

  printf("%d\n", resultado);

  exit(EXIT_SUCCESS);
}
