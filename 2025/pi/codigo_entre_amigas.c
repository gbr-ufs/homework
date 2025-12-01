#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Entrada.
  char frase[513];
  // Saída.
  char caracteres[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                         'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                         'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  do {
    scanf("%s", frase);

    for (int i = 0; i < 27; i++) {
      char *endptr;
      int frase_valor = strtoimax(frase, &endptr, 10);

      if (frase_valor == i) {
        printf("%c", caracteres[i]);
      }
    }
  } while ((strcmp(frase, "fim")));

  exit(EXIT_SUCCESS);
}
