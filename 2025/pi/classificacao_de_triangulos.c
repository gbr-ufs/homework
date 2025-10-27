#include <stdio.h>

int diferentes(double primeiro, double segundo, double terceiro) {
  if (primeiro != segundo && segundo != terceiro && primeiro != terceiro) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  double primeiro, segundo, terceiro;

  scanf("%ld %ld %ld", &primeiro, &segundo, &terceiro);

  if (primeiro == segundo && segundo == terceiro) {
    printf("equilatero\n");
  } else if (diferentes(primeiro, segundo, terceiro)) {
    printf("escaleno\n");
  } else {
    printf("isosceles\n");
  }

  return 0;
}
