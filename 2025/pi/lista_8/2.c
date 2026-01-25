#include <stdio.h>

void de_n_ate_zero(int n) {
  if (n < 0) {
    return;
  }

  printf("%d\n", n);
  de_n_ate_zero(n - 1);
}

int main() {
  int n;

  scanf("%d", &n);

  de_n_ate_zero(n);

  return 0;
}
