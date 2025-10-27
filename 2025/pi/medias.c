#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Entrada.
  char tipo;
  long primeiro, segundo, terceiro;
  // Saída.
  double media;

  scanf("%c %ld %ld %ld", &tipo, &primeiro, &segundo, &terceiro);

  if (tipo == 'A') {
    media = (primeiro + segundo + terceiro) / 3.0;
  } else if (tipo == 'H') {
    media = 3.0 / (1.0 / primeiro + 1.0 / segundo + 1.0 / terceiro);
  } else if (tipo == 'G') {
    media = pow((primeiro * segundo * terceiro), 1.0 / 3.0);
  } else {
    exit(EXIT_FAILURE);
  }

  printf("%0.3lf", media);

  return 0;
}
