#include <stdio.h>

int main() {
  float valor;
  float gorgeta;

  scanf("%f", &valor);
  gorgeta = valor * 0.1;
  printf("%0.2f\n", valor + gorgeta);

  return 0;
}
