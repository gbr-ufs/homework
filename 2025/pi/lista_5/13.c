#include <stdio.h>

int main() {
  int m[4][4];
  int soma = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &m[i][j]);
      soma += m[i][j];
    }
    printf("soma: %d\n", soma);
  }

  return 0;
}
