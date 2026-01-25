#include <stdio.h>

int substring(char *primeira, char *segunda) {
  for (int i = 0; primeira[i] != '\0'; i++) {
    int j = 0;

    while (primeira[i + j] == segunda[j] && segunda[j] != '\0') {
      j++;
    }

    if (segunda[j] == '\0') {
      return 1;
    }
  }

  return 0;
}

int main() {
  char primeira[257];
  char segunda[257];
  int resultado;

  scanf("%256s", primeira);
  scanf("%256s", segunda);

  resultado = substring(primeira, segunda);

  if (resultado) {
    printf("%s é substring de %s\n", segunda, primeira);
  }

  return 0;
}
