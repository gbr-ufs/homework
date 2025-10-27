#include <stdio.h>

int main() {
  long n;

  scanf("%ld", &n);

  if (n > 0) {
    printf("POSITIVO ");
  } else if (n < 0) {
    printf("NEGATIVO ");
  } else {
    printf("NULO\n");

    return 0;
  }

  if (n % 2 == 0) {
    printf("PAR\n");
  } else {
    printf("IMPAR\n");
  }

  return 0;
}
