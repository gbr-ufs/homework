#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;

  scanf("%d", &n);
  int array[n];
  int unico[n];
  int unico_indice = 0;
  int unico_length;

  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      unico[unico_indice++] = array[i];
    } else {
      for (int j = 0; j < i; j++) {
        if (array[j] == array[i]) {
          break;
        } else if (j == i - 1) {
          unico[unico_indice++] = array[i];
        }
      }
    }
  }

  unico_length = unico_indice + 1;

  for (int i = 0; i < unico_length; i++) {
    for (int j = i + 1; j < unico_length; j++) {
      if (unico[j] < unico[i]) {
        int tmp = unico[i];
        unico[i] = unico[j];
        unico[j] = tmp;
      }
    }
  }

  for (int i = 1; i < unico_length; i++) {
    if (i < unico_length - 1) {
      printf("%d ", unico[i]);
    } else {
      printf("%d\n", unico[i]);
    }
  }

  exit(EXIT_SUCCESS);
}
