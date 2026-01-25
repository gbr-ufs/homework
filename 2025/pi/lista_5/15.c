#include <stdio.h>

int main() {
  int m[2][2];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &m[i][j]);
      if (m[i][j] % 2 != 0) {
        printf("15: somente números pares permitidos. Insire o número "
               "novamente:\n");
        scanf("%d", &m[i][j]);
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d\n", m[i][j]);
    }
  }

  return 0;
}
