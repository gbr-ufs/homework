#include <stdio.h>

int main() {
  long primeiro, segundo, terceiro;

  scanf("%ld %ld %ld", &primeiro, &segundo, &terceiro);

  if (primeiro <= segundo && primeiro <= terceiro) {
    printf("%ld\n", primeiro);
  } else if (segundo <= primeiro && segundo <= terceiro) {
    printf("%ld\n", segundo);
  } else {
    printf("%ld\n", terceiro);
  }

  return 0;
}
