#include <stdio.h>

int main() {
  const double PI = 3.14159;
  double a, b, c;
  double area_triangulo, area_circulo, area_trapezio, area_quadrado,
      area_retangulo;

  scanf("%lf %lf %lf", &a, &b, &c);
  area_triangulo = (a * c) / 2.0;
  area_circulo = PI * (c * c);
  area_trapezio = ((a + b) * c) / 2.0;
  area_quadrado = b * b;
  area_retangulo = a * b;
  printf("TRIANGULO: %0.3lf\n", area_triangulo);
  printf("CIRCULO: %0.3lf\n", area_circulo);
  printf("TRAPEZIO: %0.3lf\n", area_trapezio);
  printf("QUADRADO: %0.3lf\n", area_quadrado);
  printf("RETANGULO: %0.3lf\n", area_retangulo);

  return 0;
}
