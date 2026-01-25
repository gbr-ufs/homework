#include <stdio.h>

struct habitante {
  double salario;
  int idade;
  int quantidade_filhos;
}

int main() {
  struct habitante habitantes[20];
  double soma_salarios = 0.0;
  double media_salarios;
  int soma_filhos = 0;
  double media_filhos;
  double maior_salario;

  for (int i = 0; i < 20; i++) {
    double salario;

    scanf("%lf", &salario);

    while (salario < 0.0) {
      printf("9: Salário inválido, tente novamente\n");
      scanf("%lf", &salario);
    }

    habitantes[i].salario = salario;
    soma_salarios += salario;

    int idade;

    scanf("%d", &idade);

    while (idade < 0) {
      printf("9: Idade inválida, tente novamente\n");
      scanf("%d", &idade);
    }

    habitantes[i].idade = idade;

    int quantidade_filhos;

    scanf("%d", &quantidade_filhos);

    while (quantidade_filhos < 0) {
      printf("9: Quantidade de filhosinválida, tente novamente\n");
      scanf("%d", &quantidade_filhos);
    }

    habitantes[i].quantidade_filhos = quantidade_filhos;
    soma_filhos += quantidade_filhos;
  }

  maior_salario = habitantes[0].salario;

  for (int i = 1; i < 20; i++) {
    if (maior_salario < habitantes[i].salario) {
      maior_salario = habitantes[i].salario;
    }
  }

  media_salarios = soma_salarios / 20.0;
  media_filhos = soma_filhos / 20.0;

  printf("Média de salário da população: R$ %.2lf\n", media_salarios);
  printf("Média do número de filhos da população: R$ %.2lf\n", media_filhos);
  printf("Maior salário: R$ %.2lf\n", maior_salario);

  return 0;
}
