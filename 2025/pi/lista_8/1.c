#include <stdio.h>

void de_zero_ate_n(int n, int step) {
  if (step > n) {
    return;
  }

  printf("%d\n", step);
  de_zero_ate_n(n, step + 1);
}

int main() {
  int n;

  scanf("%d", &n);

  de_zero_ate_n(n, 0);

  return 0;
}
