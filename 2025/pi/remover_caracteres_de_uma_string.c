#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char frase[80], letras[80];
  int frase_length, letras_length;

  scanf("%s %s", frase, letras);
  frase_length = strlen(frase);
  letras_length = strlen(letras);

  for (int i = 0; i < frase_length; i++) {
    int printar = 1;
    for (int j = 0; j < letras_length; j++) {
      if (frase[i] == letras[j]) {
        printar = 0;
      }
    }
    if (printar) {
      printf("%c", frase[i]);
    }
  }

  printf("\n");

  exit(EXIT_SUCCESS);
}
