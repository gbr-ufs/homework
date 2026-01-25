#include <stdio.h>

int main() {
  int primeiro;
  int segundo;

  scanf("%d", &primeiro);
  scanf("%d", &segundo);

  if (&primeiro > &segundo) {
    printf("%d: %p\n", primeiro, &primeiro);
  } else {
    printf("%d: %p\n", segundo, &segundo);
  }

  return 0;
}
