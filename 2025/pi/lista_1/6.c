#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 0;
  printf("%d\n", ++i);
  --i;
  printf("%d\n", i++);

  exit(EXIT_SUCCESS);
}
