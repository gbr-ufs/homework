#include <stdio.h>

int main() {
  // Entrada.
  double largura, comprimento, altura;

  scanf("%lf %lf %lf", &largura, &comprimento, &altura);

  if (largura <= 45 && comprimento <= 56 && altura <= 25) {
    printf("PERMITIDA\n");
  } else {
    printf("PROIBIDA\n");
  }

  return 0;
}
