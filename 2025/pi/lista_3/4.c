#include <stdio.h>
#include <stdlib.h>

int main() {
  int primeiro;
  int segundo;
  int terceiro;
  int tmp;

  scanf("%d", &primeiro);
  scanf("%d", &segundo);
  scanf("%d", &terceiro);

  if (primeiro > segundo) {
    tmp = primeiro;
    primeiro = segundo;
    segundo = tmp;
  }

  if (primeiro > terceiro) {
    tmp = primeiro;
    primeiro = terceiro;
    terceiro = tmp;
  }

  if (segundo > terceiro) {
    tmp = segundo;
    segundo = terceiro;
    terceiro = tmp;
  }

  printf("%d %d %d\n", primeiro, segundo, terceiro);
  printf("%d %d %d\n", terceiro, segundo, primeiro);

  exit(EXIT_SUCCESS);
}
