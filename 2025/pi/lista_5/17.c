#include <stdio.h>

int main() {
  int m[3][4];
  int constante;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  printf("Constante: ");
  scanf("%d", &constante);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] *= constante;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d\n", m[i][j]);
    }
  }

  return 0;
}
