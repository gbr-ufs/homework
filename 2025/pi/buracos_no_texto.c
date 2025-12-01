#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// buracos no texto.
// espaço vazio numa letra.
// o "A" tem um, o "B" tem dois, "C" não tem.

int main() {
  int t;
  long soma = 0;
  char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char um_buraco[6] = {'A', 'D', 'O', 'P', 'Q', 'R'};
  int um_buraco_length = 6;
  char dois_buracos[1] = {'B'};
  int dois_buracos_length = 1;

  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    char texto[100];
    scanf("%s", texto);
    int texto_length = strlen(texto);

    for (int j = 0; j < texto_length; j++) {
      for (int k = 0; k < um_buraco_length; k++) {
        if (texto[j] == um_buraco[k]) {
          soma++;
        }
      }
      for (int l = 0; l < dois_buracos_length; l++) {
        if (texto[j] == dois_buracos[l]) {
          soma += 2;
        }
      }
    }

    printf("%ld\n", soma);
    soma = 0;
  }

  exit(EXIT_SUCCESS);
}
