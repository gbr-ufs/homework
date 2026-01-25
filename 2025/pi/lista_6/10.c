#include <stdio.h>

int main() {
  char a[11];
  char b[11];
  char intercalacao[21];

  scanf("%10s", a);
  scanf("%10s", b);

  int i = 0;
  int j = 0;
  while (a[j] != '\0' && b[j] != '\0') {
    intercalacao[i] = a[j];
    i++;
    intercalacao[i] = b[j];
    i++;
    j++;
  }

  while (a[j] != '\0') {
    intercalacao[i] = a[j];
    i++;
    j++;
  }

  while (b[j] != '\0') {
    intercalacao[i] = b[j];
    i++;
    j++;
  }

  intercalacao[i] = '\0';

  printf("%s\n", intercalacao);

  return 0;
}
