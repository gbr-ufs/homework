#include <stdio.h>

int main() {
  int m[4][4];
  int maior;
  int r[4][4];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &m[i][j]);
      r[i][j] = m[i][j];
    }
  }

  maior = m[0][0];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (maior < m[i][j]) {
        maior = m[i][j];
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      r[i][j] *= maior;
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d\n", r[i][j]);
    }
  }

  return 0;
}
