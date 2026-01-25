#include <stdio.h>

int main() {
  int ints[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", *&ints + i);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", (*ints + i) * 2);
  }

  return 0;
}
