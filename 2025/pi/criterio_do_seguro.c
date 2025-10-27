#include <stdio.h>

int main() {
  int primeiro, segundo;

  scanf("%d %d", &primeiro, &segundo);

  if (!primeiro && segundo) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}
