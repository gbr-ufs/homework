#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho;

  scanf("%d", &tamanho);
  int primeiro[tamanho];
  int segundo[tamanho];

  for (int i = 0; i < tamanho * 2; i++) {
    int valor;

    scanf("%d", &valor);

    if (i < tamanho) {
      primeiro[i] = valor;
    } else {
      segundo[i - tamanho] = valor;
    }
  }

  for (int i = 0; i < tamanho; i++) {
    printf("%d\n%d\n", primeiro[i], segundo[i]);
  }

  exit(EXIT_SUCCESS);
}
