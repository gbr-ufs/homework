#include <stdio.h>

int consulta(int valor, int m[5][8]) {
  int encontrado = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      if (m[i][j] == valor) {
        encontrado = 1;
        printf("m[%d][%d]\n", i, j);
      }
    }
  }

  return encontrado;
}

int main() {
  int m[5][8];
  int valor_pesquisa;
  char resposta;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  printf("Escolha o valor para pesquisa: ");
  scanf("%d", &valor_pesquisa);

  if (!consulta(valor_pesquisa, m)) {
    printf("20: Valor não encontrado\n");
  }

  printf("Realizar consulta novamente (y ou n)? ");
  scanf(" %c", &resposta);

  if (resposta == 'y') {
    scanf("%d", &valor_pesquisa);
    consulta(valor_pesquisa, m);
  }

  return 0;
}
