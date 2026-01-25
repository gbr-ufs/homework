#include <stdio.h>

int main() {
  char string[51];
  char vogais[] = "aeiou";
  int contagem = 0;

  scanf("%s", string);

  for (int i = 0; string[i] != '\0'; i++) {
    for (int j = 0; vogais[j] != '\0'; j++) {
      if (string[i] == vogais[j]) {
        contagem++;
      }
    }
  }

  printf("%d\n", contagem);

  return 0;
}
