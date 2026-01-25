#include <stdio.h>
#include <string.h>

struct habitante {
  char sexo;
  float altura;
  int idade;
  char cor_olhos[257];
};

// O critério específico é: olhos castanhos e altura superior a 1,60 m.
int se_encaixa_no_criterio_especifico(struct habitante habitante) {
  return (strcmp(habitante.cor_olhos, "Castanhos") == 0 &&
          habitante.altura > 1.6);
}

int main() {
  struct habitante habitantes[50];
  int maior_idade;
  int soma_idade_criterios_especificos = 0;
  float media_idade_criterios_especificos;
  int quantidade_homens = 0;
  float percentual_homens;

  for (int i = 0; i < 50; i++) {
    char sexo;

    scanf("%c", &sexo);

    while (sexo != 'F' || sexo != 'M') {
      printf("10: Sexo inválido, tente novamente\n");
      scanf("%c", &sexo);
    }

    habitantes[i].sexo = sexo;

    if (sexo == 'M') {
      quantidade_homens++;
    }

    float altura;

    scanf("%f", &altura);

    while (altura < 0.0) {
      printf("10: Altura inválida, tente novamente\n");
      scanf("%f", &altura);
    }

    habitantes[i].altura = altura;

    int idade;

    scanf("%d", &idade);

    while (idade < 0) {
      printf("10: Idade inválida, tente novamente\n");
      scanf("%d", &idade);
    }

    habitantes[i].idade = idade;

    scanf("%256s", habitantes[i].cor_olhos);

    if (se_encaixa_no_criterio_especifico(habitantes[i])) {
      soma_idade_criterios_especificos++;
    }
  }

  maior_idade = habitantes[0].idade;

  for (int i = 1; i < 50; i++) {
    if (maior_idade < habitantes[i].idade) {
      maior_idade = habitantes[i].idade;
    }
  }

  media_idade_criterios_especificos = soma_idade_criterios_especificos / 50.0;
  percentual_homens = quantidade_homens / 100.0;

  printf("Maior idade: %d\n", maior_idade);
  printf("Média de pessoas que se encaixam nos critérios específicos: %f\n",
         media_idade_criterios_especificos);
  printf("Percentual de homens %.2f%%\n", percentual_homens);

  return 0;
}
