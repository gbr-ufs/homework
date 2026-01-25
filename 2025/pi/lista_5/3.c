#include <stdio.h>

int main() {
  int numeros[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &numeros[i]);
  }

  int j = 0;
  for (int i = 9; i >= 5; --i) {
    int tmp = numeros[j];
    numeros[j] = numeros[i];
    numeros[i] = tmp;
    j++;
  }

  printf("original\n");
  for (int i = 9; i >= 0; --i) {
    printf("%d\n", numeros[i]);
  }

  printf("invertido\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", numeros[i]);
  }

  return 0;
}
