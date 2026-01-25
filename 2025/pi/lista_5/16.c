#include <stdio.h>

int main() {
  int m[10][3];
  int menor;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  for (int i = 0; i < 10; i++) {
    menor = m[i][0];

    for (int j = 1; j < 3; j++) {
      if (menor > m[i][j]) {
        menor = m[i][j];
      }
    }

    printf("Aluno %d: %d\n", i + 1, menor);
  }

  return 0;
}
