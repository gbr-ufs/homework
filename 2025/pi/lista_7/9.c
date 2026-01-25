#include <stdio.h>

int maior_entre_tres(int primeiro, int segundo, int terceiro) {
  if (primeiro >= segundo && primeiro >= terceiro) {
    return primeiro;
  }

  if (segundo >= primeiro && segundo >= terceiro) {
    return segundo;
  }

  if (terceiro >= primeiro && terceiro >= segundo) {
    return terceiro;
  }

  return primeiro;
}

int main() {
  int primeiro;
  int segundo;
  int terceiro;
  int maior;

  scanf("%d", &primeiro);
  scanf("%d", &segundo);
  scanf("%d", &terceiro);

  maior = maior_entre_tres(primeiro, segundo, terceiro);

  printf("%d\n", maior);

  return 0;
}
