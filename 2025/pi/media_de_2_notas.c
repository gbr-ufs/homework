#include <stdio.h>

int main() {
  // Entrada.
  float primeira_nota, segunda_nota;
  // Saída.
  float media_aritmetica;

  scanf("%f %f", &primeira_nota, &segunda_nota);
  media_aritmetica = (primeira_nota + segunda_nota) / 2;
  printf("%0.2f\n", media_aritmetica);

  return 0;
}
