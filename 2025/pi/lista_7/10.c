#include <stdio.h>

int check_lados(double lado1, double lado2, double lado3) {
  return lado1 + lado2 >= lado3;
}

int e_triangulo(double lado1, double lado2, double lado3) {
  int um_mais_dois = check_lados(lado1, lado2, lado3);
  int um_mais_tres = check_lados(lado1, lado3, lado2);
  int dois_mais_tres = check_lados(lado2, lado3, lado1);

  return um_mais_dois && um_mais_tres && dois_mais_tres;
}

char *classifique_triangulo(double lado1, double lado2, double lado3) {
  if (!e_triangulo(lado1, lado2, lado3)) {
    return "Inválido";
  }

  int condicao_equilatero = lado1 == lado2 && lado2 == lado3;
  int condicao_isosceles = lado1 == lado2 || lado1 == lado3 || lado2 == lado3;

  if (condicao_equilatero) {
    return "Equilátero";
  }

  if (condicao_isosceles) {
    return "Isósceles";
  }

  return "Escaleno";
}

int main() {
  double lado1;
  double lado2;
  double lado3;
  char *resultado;

  scanf("%lf", &lado1);
  scanf("%lf", &lado2);
  scanf("%lf", &lado3);

  resultado = classifique_triangulo(lado1, lado2, lado3);

  printf("%s\n", resultado);

  return 0;
}
