#include <stdio.h>
#include <stdlib.h>

long intermediario_3(long primeiro, long segundo, long terceiro) {
  if ((primeiro > segundo && primeiro < terceiro) ||
      (primeiro < segundo && primeiro > terceiro)) {
    return primeiro;
  } else if ((segundo > primeiro && segundo < terceiro) ||
             (segundo < primeiro && segundo > terceiro)) {
    return segundo;
  } else {
    return terceiro;
  }
}

int main() {
  long primeiro, segundo, terceiro;

  scanf("%ld %ld %ld", &primeiro, &segundo, &terceiro);

  printf("%ld\n", intermediario_3(primeiro, segundo, terceiro));

  exit(EXIT_SUCCESS);
}
