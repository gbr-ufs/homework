#include <stdio.h>

int main() {
  char string[51];
  int contagem = 0;

  scanf("%[^\n]", string);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == ' ') {
      contagem++;
    }
  }

  printf("%d\n", contagem + 1);

  return 0;
}
