#include <stdio.h>

int main() {
  int m[3][5];
  int maior;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  maior = m[0][0];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      if (maior < m[i][j]) {
        maior = m[i][j];
      }
    }
  }

  printf("%d\n", maior);

  return 0;
}
