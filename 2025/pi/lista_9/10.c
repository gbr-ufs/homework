#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;

  scanf("%d", &n);

  int **identidade = calloc(n, sizeof(n));

  for (int i = 0; i < n; i++) {
    identidade[i] = calloc(n, sizeof(n));
  }

  for (int i = 0; i < n; i++) {
    identidade[i][i] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf(" %d ", identidade[i][j]);
    }
    printf("\n");
  }

  return 0;
}
