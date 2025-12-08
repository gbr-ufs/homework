#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// até 300 convidados.
// ordenar alfabeticamente uma lista de convidados.
// inserir até mais 5 pessoas na lista.

int comparador(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  char entrada[257];
  char convidados[300][257];

  int convidados_length = 0;

  while (1) {
    scanf(" %[^\n]", entrada);
    if (!strcmp(entrada, "FIM")) {
      break;
    }

    strcpy(convidados[convidados_length++], entrada);
  }

  qsort(convidados, convidados_length, sizeof(convidados[0]), comparador);

  for (int i = 0; i < convidados_length; i++) {
    printf("%s\n", convidados[i]);
  }

  printf("--------------------------------------------------\n");

  int sequencia;

  while (1) {
    scanf("%d", &sequencia);

    if (sequencia == 0) {
      break;
    }

    for (int i = 0; i < sequencia; i++) {

      scanf(" %[^\n]", entrada);

      // Insertion Sort.
      int j = convidados_length - 1;

      while (j >= 0 && strcmp(convidados[j], entrada) > 0) {
        strcpy(convidados[j + 1], convidados[j]);
        j--;
      }

      strcpy(convidados[j + 1], entrada);
      convidados_length++;
    }
  }

  for (int i = 0; i < convidados_length; i++) {
    printf("%s\n", convidados[i]);
  }

  printf("--------------------------------------------------\n");

  exit(EXIT_SUCCESS);
}
