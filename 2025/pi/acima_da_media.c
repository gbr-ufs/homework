#include <stdio.h>

int main() {
  // Entrada.
  double primeiro, segundo, terceiro;
  // Saída.
  double soma, media;
  int quantidade = 0;

  scanf("%lf %lf %lf", &primeiro, &segundo, &terceiro);
  soma = primeiro + segundo + terceiro;
  media = soma / 3.0;
  quantidade = (primeiro > media) + (segundo > media) + (terceiro > media);
  printf("%d\n", quantidade);

  return 0;
}
