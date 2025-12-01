#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char string[256];
  int string_length;

  scanf("%s", string);
  string_length = strlen(string);

  for (int i = string_length - 1; i >= 0; i--) {
    printf("%c", string[i]);
  }

  printf("\n");

  exit(EXIT_SUCCESS);
}
