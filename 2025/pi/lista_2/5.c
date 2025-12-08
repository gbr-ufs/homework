#include <stdio.h>
#include <stdlib.h>

double area_circulo(double raio) {
  const double PI = 3.1415;

  return (raio * raio) * PI;
}

int main() {
  double raio;

  scanf("%lf", &raio);

  printf("%0.4lf\n", area_circulo(raio));

  exit(EXIT_SUCCESS);
}
