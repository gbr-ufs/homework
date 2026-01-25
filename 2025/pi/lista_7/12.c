#include <stdio.h>

// Soma aberta.
int soma_entre(int primeiro, int segundo) {
  int resultado = 0;

  if (primeiro == segundo) {
    return resultado;
  }

  if (primeiro > segundo) {
    for (int i = segundo + 1; i < primeiro; i++) {
      resultado += i;
    }
  } else {
    for (int i = segundo - 1; i > primeiro; i--) {
      resultado += i;
    }
  }

  return resultado;
}

int main() {
  int primeiro;
  int segundo;
  int soma;

  scanf("%d", &primeiro);
  scanf("%d", &segundo);

  soma = soma_entre(primeiro, segundo);

  printf("%d\n", soma);

  return 0;
}
