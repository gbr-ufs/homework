#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;

  scanf("%d", &n);

  int *vetor = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &*vetor + i);
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", *vetor + i);
  }

  return 0;
}
