#include <stdio.h>

int primeiros_n_cubos(int n, int acc) {
  if (n == 1) {
    return acc;
  }

  return primeiros_n_cubos(n - 1, acc + n * n * n);
}

int main() {
  int n;
  int cubos;

  scanf("%d", &n);

  cubos = primeiros_n_cubos(n, 1);

  printf("%d\n", cubos);

  return 0;
}
