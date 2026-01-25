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
  int numero;

  scanf("%d", &numero);

  if (e_primo(numero)) {
    printf("É primo\n");
  } else {
    printf("Não é primo\n");
  }

  return 0;
}
