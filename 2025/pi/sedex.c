#include <stdio.h>

int main() {
  // Entrada.
  long diametro, altura, largura, profundidade;

  scanf("%ld %ld %ld %ld", &diametro, &altura, &largura, &profundidade);

  if (diametro <= altura && diametro <= largura && diametro <= profundidade) {
    printf("S\n");
  } else {
    printf("N\n");
  }

  return 0;
}
