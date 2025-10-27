#include <stdio.h>

int main() {
  const double PI = 3.14159;
  // Entrada.
  double raio;
  // Saída.
  double area;

  scanf("%lf", &raio);
  // Conversão de centímetros para metros.
  raio *= 0.01;
  area = PI * (raio * raio);
  printf("Area = %0.4lf\n", area);

  return 0;
}
