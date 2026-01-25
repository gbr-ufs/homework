#include <stdio.h>

int main() {
  int positivos[8];
  int negativos[8];

  int j = 0;
  for (int i = 0; i < 8; i++) {
    int numero;

    scanf("%d", &numero);

    while (numero < 0) {
      if (j < 8) {
        negativos[j] = numero;
        j++;
      }

      scanf("%d", &numero);
    }

    positivos[i] = numero;
  }

  printf("positivos\n");
  for (int i = 0; i < 8; i++) {
    printf("%d\n", positivos[i]);
  }

  printf("negativos\n");
  for (int i = 0; i < j; i++) {
    printf("%d\n", negativos[i]);
  }

  return 0;
}
