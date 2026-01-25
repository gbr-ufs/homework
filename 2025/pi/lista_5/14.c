#include <stdio.h>

int main() {
  int m[4][4];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  for (int i = 0; i < 4; i++) {
    int tmp = m[0][i];

    m[0][i] = m[3][i];
    m[3][i] = tmp;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d\n", m[i][j]);
    }
  }

  return 0;
}
