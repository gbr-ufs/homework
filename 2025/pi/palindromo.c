#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para remover espaços.
// Veja: <https://www.geeksforgeeks.org/dsa/remove-spaces-from-a-given-string/>.
void remover_espacos(char *str) {
  int contagem = 0;

  for (int i = 0; str[i]; i++) {
    if (str[i] != ' ') {
      str[contagem++] = str[i];
    }
  }

  str[contagem] = '\0';
}

// Função para inverter uma string sem usar printf.
// Veja: <https://stackoverflow.com/a/784455>.
void inverter_uma_string(char *str) {
  char *inicio = str;
  char *fim = inicio + strlen(str) - 1;
  char tmp;

  while (fim > inicio) {
    tmp = *inicio;
    *inicio = *fim;
    *fim = tmp;

    ++inicio;
    --fim;
  }
}

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

void normalizar(char *str) {
  remover_espacos(str);
  maiuscula_pra_minuscula(str);
}

int main() {
  int n;

  scanf("%d ", &n);

  for (int i = 0; i < n; i++) {
    char frase[256], invertida[256];

    scanf(" %[^\n]", frase);
    normalizar(frase);
    strcpy(invertida, frase);
    inverter_uma_string(invertida);

    if (strcmp(frase, invertida)) {
      printf("NAO\n");
    } else {
      printf("SIM\n");
    }
  }

  exit(EXIT_SUCCESS);
}
