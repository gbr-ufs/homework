#include <stdio.h>

int main() {
  int ints[5];

  for (int i = 0; i < 5; i++) {
    scanf("%d", &ints[i]);
  }

  for (int i = 0; i < 5; i++) {
    if (ints[i] % 2 == 0) {
      printf("%p\n", &ints[i]);
    }
  }

  return 0;
}
