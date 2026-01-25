#include <stdio.h>

struct pessoa {
  char nome[257];
  char sexo;
  int idade;
};

int main() {
  struct pessoa pessoas[10];

  for (int i = 0; i < 10; i++) {
    scanf("%256s", pessoas[i].nome);

    char sexo;

    scanf(" %c", &sexo);

    while (sexo != 'F' || sexo != 'M') {
      printf("5: Sexo inválido, tente novamente\n");
      scanf(" %c", &sexo);
    }

    pessoas[i].sexo = sexo;

    int idade;

    scanf("%d", &idade);

    while (idade < 0) {
      printf("5: Idade inválida, tente novamente\n");
      scanf("%d", &idade);
    }

    pessoas[i].idade = idade;
  }

  for (int i = 0; i < 10; i++) {
    if (pessoas[i].sexo == 'F') {
      printf("Nome: %s Sexo: %c Idade: %d\n", pessoas[i].nome, pessoas[i].sexo,
             pessoas[i].idade);
    }
  }

  return 0;
}
