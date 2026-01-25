#include <stdio.h>

int main() {
  char string[11];
  char vogal_minuscula[] = "aeiou";
  char vogal_maiuscula[] = "AEIOU";

  scanf("%s", string);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      if (string[i] == vogal_minuscula[j]) {
        string[i] = vogal_maiuscula[j];
      }
    }
  }

  printf("%s\n", string);

  return 0;
}
