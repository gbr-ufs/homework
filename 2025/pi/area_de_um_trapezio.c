#include <stdio.h>

int main() {
  // Entrada.
  long base_menor, base_maior, base, altura;
  // Saída.
  double area;

  scanf("%ld %ld %ld", &base_maior, &base_menor, &altura);
  base = base_maior + base_menor;
  area = (base * altura) / 2.0;
  printf("%0.1lf\n", area);

  return 0;
}
