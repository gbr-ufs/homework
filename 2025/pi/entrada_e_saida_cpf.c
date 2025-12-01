#include <stdio.h>
#include <stdlib.h>

int main() {
  char cpf[15];

  scanf("%s", cpf);

  for (int i = 0; i < 14; i++) {
    if (cpf[i] == '.' || cpf[i] == '-') {
      printf("\n");
    } else {
      printf("%c", cpf[i]);
    }
  }

  printf("\n");

  exit(EXIT_SUCCESS);
}
