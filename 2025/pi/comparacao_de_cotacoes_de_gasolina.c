#include <stdio.h>
#include <stdlib.h>

double valor_galao_para_valor_litro(double valor_litro_eua,
                                    double taxa_de_conversao) {
  return (valor_litro_eua * taxa_de_conversao) / 3.8;
}

int main() {
  double valor_litro_eua;
  double valor_galao_convertido;
  double valor_litro;
  double taxa_de_conversao;

  scanf("%lf %lf %lf", &valor_litro_eua, &valor_litro, &taxa_de_conversao);

  valor_galao_convertido =
      valor_galao_para_valor_litro(valor_litro_eua, taxa_de_conversao);

  printf("Gasolina EUA: R$ %0.2lf\n", valor_galao_convertido);
  printf("Gasolina Brasil: R$ %0.2lf\n", valor_litro);

  if (valor_galao_convertido > valor_litro) {
    printf("Mais barata no Brasil\n");
  } else if (valor_galao_convertido == valor_litro) {
    printf("Igual\n");
  } else {
    printf("Mais barata nos EUA\n");
  }

  exit(EXIT_SUCCESS);
}
