#include <stdio.h>

int main() {
  int m[3][5];
  int m_transposta[5][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      m_transposta[i][j] = m[j][i];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      printf(" %d ", m_transposta[j][i]);
    }
    printf("\n");
  }

  return 0;
}
