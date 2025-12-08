#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maiuscula_pra_minuscula(char *str) {
  int str_length = strlen(str);
  char maiuscula[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char minuscula[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  for (int i = 0; i < str_length; i++) {
    for (int j = 0; j < 26; j++) {
      if (str[i] == maiuscula[j]) {
        str[i] = minuscula[j];
      }
    }
  }
}

int main() {
  char entrada[5];
  int votos_sim = 0;
  int votos_nao = 0;
  int votos_nulos = 0;
  int votos_negativos = 0;

  scanf("%s", entrada);
  entrada[strlen(entrada) + 1] = '\0';
  maiuscula_pra_minuscula(entrada);

  while (strcmp(entrada, "encerrar")) {
    if (!strcmp(entrada, "sim")) {
      votos_sim++;
    } else if (!strcmp(entrada, "nao")) {
      votos_nao++;
    } else {
      votos_nulos++;
    }

    scanf("%s", entrada);
    entrada[strlen(entrada) + 1] = '\0';
    maiuscula_pra_minuscula(entrada);
  }

  votos_negativos = votos_nao + votos_nulos;

  if (votos_sim > votos_negativos) {
    printf("COM FOGOS\n");
  } else {
    printf("SEM FOGOS\n");
  }

  exit(EXIT_SUCCESS);
}
