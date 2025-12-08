#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho;
  int menor;
  int indice;

  scanf("%d", &tamanho);
  int numeros[tamanho];

  scanf("%d", &numeros[0]);
  menor = numeros[0];
  indice = 0;

  for (int i = 1; i < tamanho; i++) {
    int valor;

    scanf("%d", &valor);

    numeros[i] = valor;

    if (numeros[i] < menor) {
      menor = numeros[i];
      indice = i;
    }
  }

  printf("Menor valor: %d\n", menor);
  printf("Posicao: %d\n", indice);

  exit(EXIT_SUCCESS);
}
