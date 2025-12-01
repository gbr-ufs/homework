#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char numero[513];
  int numero_length;
  long soma = 0;

  scanf("%s", numero);
  numero_length = strlen(numero);

  for (int i = 0; i < numero_length; i++) {
    // Veja: <https://stackoverflow.com/a/5030086>.
    int valor = numero[i] - '0';

    soma += valor;
  }

  printf("%ld\n", soma);

  exit(EXIT_SUCCESS);
}
