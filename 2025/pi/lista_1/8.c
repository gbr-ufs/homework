#include <stdio.h>
#include <stdlib.h>

int main() {
  int numero = 3;

  printf("%d\n", numero);
  float numero_float = (float)numero;
  printf("%f\n", numero_float);
  double numero_double = (double)numero;
  printf("%lf\n", numero_double);

  exit(EXIT_SUCCESS);
}
