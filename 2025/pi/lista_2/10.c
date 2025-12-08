#include <stdio.h>
#include <stdlib.h>

float valor_consulta(float altura, float peso, int idade) {
  return altura * peso + (float)idade;
}

int main() {
  float peso;
  int idade;
  float altura;

  scanf("%f %d %f", &peso, &idade, &altura);

  printf("R$ %0.2f\n", valor_consulta(altura, peso, idade));

  exit(EXIT_SUCCESS);
}
