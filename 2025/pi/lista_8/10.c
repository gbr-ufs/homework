#include <stdio.h>

int fatorial(int n) {
  if (n == 1) {
    return 1;
  }

  return n * fatorial(n - 1);
}

int main() {
  int primeiro;
  int fat;

  scanf("%d", &primeiro);

  fat = fatorial(primeiro);

  printf("%d\n", fat);

  return 0;
}
