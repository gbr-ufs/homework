#include <stdio.h>

int main() {
  // Entrada.
  int valor;
  // Saída.
  int soma = 0;

  for (int i = 0; i < 6; i++) {
    scanf("%d", &valor);
    soma += valor;
  }

  if (soma >= 100) {
    printf("Classificado\n");
  } else {
    printf("Eliminado\n");
  }

  return 0;
}
