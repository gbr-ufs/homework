#include <stdio.h>

int main() {
  int floats[10];

  for (int i = 0; i < 10; i++) {
    printf("%p\n", &floats[i]);
  }

  return 0;
}
