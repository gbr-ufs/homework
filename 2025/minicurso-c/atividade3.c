#include <stdio.h>
#include <stdlib.h>

int main() {
  int kwh;
  float cobranca = 0;

  scanf("%d", &kwh);

  if (kwh < 100) {
    cobranca = kwh * 0.25;
  } else if (kwh <= 200) {
    cobranca = kwh * 0.40;
  } else if (kwh <= 300) {
    cobranca = kwh * 0.50;
  } else {
    cobranca = kwh * 0.60;
  }
  printf("O valor a ser cobrado é: %.2f\n", cobranca);

  exit(EXIT_SUCCESS);
}
