#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Veja: <https://en.cppreference.com/w/c/string/byte/strrchr>.

int main() {
  char frase[400];

  scanf("%[^\n]", frase);

  char *ptr_ultimo_espaco = strrchr(frase, ' ');

  if (ptr_ultimo_espaco) {
    printf("%s\n", ptr_ultimo_espaco + 1);
  } else {
    printf("%s\n", frase);
  }

  exit(EXIT_SUCCESS);
}
