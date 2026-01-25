#include <stdio.h>

int multiplicacao_soma_sucessiva(int n, int vezes, int original) {
  if (vezes == 0) {
    return 0;
  }

  if (vezes == 1) {
    return n;
  }

  return multiplicacao_soma_sucessiva(original + n, vezes - 1, original);
}

int main() {
  int n;
  int vezes;
  int resultado;

  scanf("%d", &n);
  scanf("%d", &vezes);

  resultado = multiplicacao_soma_sucessiva(n, vezes, n);

  printf("%d\n", resultado);

  return 0;
}
