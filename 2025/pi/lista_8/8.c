#include <stdio.h>

int bergamaschi(int n) {
  if (n <= 3) {
    return 1;
  }

  return bergamaschi(n - 1) + bergamaschi(n - 2) + bergamaschi(n - 3);
}

int main() {
  int n;

  scanf("%d", &n);

  printf("%d\n", bergamaschi(n));

  return 0;
}
