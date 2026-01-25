#include <stdio.h>

int main() {
  char string[257];
  int contagem = 0;

  scanf("%s", string);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == 'a') {
      contagem++;
    }
  }

  printf("%d\n", contagem);

  return 0;
}
