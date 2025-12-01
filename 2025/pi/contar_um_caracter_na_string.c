#include <stdio.h>
#include <stdlib.h>

int main() {
  char primeira[50];
  int primeira_length;
  char segunda;
  long soma = 0;

  scanf("%s %c", primeira, &segunda);
  primeira_length = sizeof(primeira) / sizeof(char);

  for (int i = 0; i < primeira_length; i++) {
    if (primeira[i] == segunda) {
      soma++;
    }
  }

  printf("%ld\n", soma);

  exit(EXIT_SUCCESS);
}
