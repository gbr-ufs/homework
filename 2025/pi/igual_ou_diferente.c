#include <stdio.h>

int diferentes(long primeiro, long segundo, long terceiro) {
  if (primeiro != segundo && segundo != terceiro && primeiro != terceiro) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  long primeiro, segundo, terceiro;

  scanf("%ld %ld %ld", &primeiro, &segundo, &terceiro);

  if (primeiro == segundo && segundo == terceiro) {
    printf("1\n");
  } else if (diferentes(primeiro, segundo, terceiro)) {
    printf("2\n");
  } else {
    printf("3\n");
  }

  return 0;
}
