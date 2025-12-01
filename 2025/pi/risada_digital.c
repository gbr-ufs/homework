#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// As consoantes não interferem no resultado.
// As mais engraçadas são aquelas em que as sequências de vogais são iguais
// da esquerda para direita e da direita pra esquerda.
// hahaha -> aaa -> engraçada
// huaauhahhuahau -> uaauauaau -> engraçada
// Palíndromos.
// huehuehue -> ueueue -> não engraçada.
// Não é um palíndromo.

void remover_caracteres(char *str, char *permitidos) {
  int contador = 0;

  for (int i = 0; str[i]; i++) {
    for (int j = 0; permitidos[j]; j++) {
      if (str[i] == permitidos[j]) {
        str[contador++] = str[i];
      }
    }
  }

  str[contador] = '\0';
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

int e_palindromo(char *palavra) {
  int palavra_length = strlen(palavra);
  char invertida[palavra_length + 1];

  strcpy(invertida, palavra);
  inverter_uma_string(invertida);

  if (strcmp(palavra, invertida)) {
    return 0;
  } else {
    return 1;
  }
}

int e_engracada(char *risada, char *permitidos) {
  remover_caracteres(risada, permitidos);

  if (e_palindromo(risada)) {
    return 1;
  } else {
    return 0;
  }
};

int main() {
  int n;
  char vogais[6] = {'a', 'e', 'i', 'o', 'u'};

  scanf("%d ", &n);

  for (int i = 0; i < n; i++) {
    char risada[257];

    // Usamos fgets e um buffer maior para impedir overflow.
    fgets(risada, sizeof(risada), stdin);
    int risada_length = strlen(risada);

    if (risada_length > 50) {
      printf("INVALIDA\n");
    } else if (e_engracada(risada, vogais)) {
      printf("ENGRACADA\n");
    } else {
      printf("SEM GRACA\n");
    }
  }

  exit(EXIT_SUCCESS);
}
