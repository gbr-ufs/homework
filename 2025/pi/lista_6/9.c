#include <stdio.h>

int main() {
  char string[257];
  char inversa[257];

  scanf("%s", string);

  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  int tamanho = i;

  int j = 0;
  for (i = tamanho - 1; i >= 0; i--) {
    inversa[j] = string[i];
    j++;
  }
  inversa[j] = '\0';

  printf("%s\n", inversa);

  return 0;
}
