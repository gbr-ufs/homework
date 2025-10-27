#include <stdio.h>

int main() {
  // Entrada.
  float a, b, c;
  // Saída.
  float peso_a = 2.0, peso_b = 3.0, peso_c = 5.0;
  float media;

  scanf("%f %f %f", &a, &b, &c);
  media = (a * peso_a + b * peso_b + c * peso_c) / (peso_a + peso_b + peso_c);
  printf("MEDIA = %0.1f\n", media);

  return 0;
}
