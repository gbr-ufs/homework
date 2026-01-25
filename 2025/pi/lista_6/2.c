#include <stdio.h>

int main() {
  char primeira[257];
  char segunda[257];
  char concatenacao[514];
  int i = 0;
  int j = 0;

  scanf("%256s", primeira);
  scanf("%256s", segunda);

  for (; primeira[i] != '\0'; i++) {
    concatenacao[j++] = primeira[i];
  }

  for (int k = 0; segunda[k] != '\0'; k++) {
    concatenacao[j++] = segunda[k];
  }

  concatenacao[j] = '\0';

  printf("%s\n", concatenacao);

  return 0;
}
