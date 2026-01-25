#include <stdio.h>

int e_primo(int numero) {
  int divisor = 2;
  int resultado = 1;

  if (numero < 2) {
    resultado = 0;
    return resultado;
  }

  while (divisor < numero) {
    if (numero % divisor == 0) {
      resultado = 0;
    }
    divisor++;
  }

  return resultado;
}

int main() {
  int numeros[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &numeros[i]);
  }

  for (int i = 0; i < 10; i++) {
    if (e_primo(numeros[i])) {
      printf("índice: %d número: %d\n", i, numeros[i]);
    }
  }

  return 0;
}
