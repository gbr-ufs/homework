#include <stdio.h>

int main() {
  char gabarito[11];
  char resposta[11];
  int pontuacao = 0;

  printf("gabarito:\n");
  scanf("%10s", gabarito);

  printf("resposta:\n");
  scanf("%10s", resposta);
  for (int i = 0; i < 10; i++) {
    if (gabarito[i] == resposta[i]) {
      pontuacao++;
    }
  }

  return 0;
}
