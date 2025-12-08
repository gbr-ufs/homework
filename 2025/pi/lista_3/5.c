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
  char mes[257];
  int resultado = 0;

  scanf("%s", mes);
  maiuscula_pra_minuscula(mes);

  if (!strcmp(mes, "janeiro")) {
    resultado = 1;
  } else if (!strcmp(mes, "fevereiro")) {
    resultado = 2;
  } else if (!strcmp(mes, "março")) {
    resultado = 3;
  } else if (!strcmp(mes, "abril")) {
    resultado = 4;
  } else if (!strcmp(mes, "maio")) {
    resultado = 5;
  } else if (!strcmp(mes, "junho")) {
    resultado = 6;
  } else if (!strcmp(mes, "julho")) {
    resultado = 7;
  } else if (!strcmp(mes, "agosto")) {
    resultado = 8;
  } else if (!strcmp(mes, "setembro")) {
    resultado = 9;
  } else if (!strcmp(mes, "outubro")) {
    resultado = 10;
  } else if (!strcmp(mes, "novembro")) {
    resultado = 11;
  } else if (!strcmp(mes, "dezembro")) {
    resultado = 12;
  }

  if (resultado != 0) {
    printf("%d\n", resultado);
  }

  exit(EXIT_SUCCESS);
}
