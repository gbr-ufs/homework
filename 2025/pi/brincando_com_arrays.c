#include <stdio.h>
#include <stdlib.h>

int main() {
  long n;

  scanf("%ld", &n);
  long array[n];

  for (long i = 0; i < n; i++) {
    scanf("%ld", &array[i]);
  }

  for (long i = n - 1; i >= 0; i--) {
    if (i > 0) {
      printf("%ld ", array[i]);
    } else {
      printf("%ld\n", array[i]);
    }
  }

  for (long i = 1; i <= n; i++) {
    if (i != n) {
      printf("%ld ", array[i]);
    } else {
      printf("%ld\n", array[0]);
    }
  }

  for (long i = 0; i < n; i++) {
    for (long j = i + 1; j < n; j++) {
      if (array[j] > array[i]) {
        long tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }

  for (long i = 0; i < n; i++) {
    if (i < n - 1) {
      printf("%ld ", array[i]);
    } else {
      printf("%ld\n", array[i]);
    }
  }

  exit(EXIT_SUCCESS);
}
