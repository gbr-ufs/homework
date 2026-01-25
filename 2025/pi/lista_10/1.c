#include <stdio.h>

struct funcionario {
  char nome[257];
  double salario;
};

int main() {
  struct funcionario funcionarios[10];
  double soma = 0.0;
  double media;

  for (int i = 0; i < 10; i++) {
    scanf("%256s", funcionarios[i].nome);
    scanf("%lf", &funcionarios[i].salario);
    soma += funcionarios[i].salario;
  }

  media = soma / 10.0;

  printf("Média dos salários: R$ %.2lf\n", media);

  return 0;
}
