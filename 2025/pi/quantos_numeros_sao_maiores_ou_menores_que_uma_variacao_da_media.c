#include <stdio.h>
#include <stdlib.h>

int main() {
  long n;
  double media = 0.0;
  double media_10_por_cento = 0.0;
  double media_mais_10_por_cento = 0.0;
  double soma = 0.0;
  long acima_da_media_mais_10_por_cento = 0;
  long abaixo_da_media_mais_10_por_cento = 0;

  scanf("%ld", &n);
  int notas[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &notas[i]);
    soma += notas[i];
  }

  media = soma / (double)n;
  media_10_por_cento = media * (10.0 / 100.0);
  media_mais_10_por_cento = media + media_10_por_cento;

  for (int i = 0; i < n; i++) {
    if (notas[i] > media_mais_10_por_cento) {
      acima_da_media_mais_10_por_cento++;
    } else if (notas[i] < media_mais_10_por_cento) {
      abaixo_da_media_mais_10_por_cento++;
    }
  }

  printf("%0.2lf\n", media);
  printf("%ld\n", acima_da_media_mais_10_por_cento);
  printf("%ld\n", abaixo_da_media_mais_10_por_cento);

  exit(EXIT_SUCCESS);
}
