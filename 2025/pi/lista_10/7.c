#include <stdio.h>
#include <string.h>

struct carro {
  char marca[257];
  char nome[257];
  int ano;
  char cor[257];
  double preco;
};

int main() {
  struct carro carros[50];

  for (int i = 0; i < 50; i++) {
    scanf("%256s", carros[i].marca);
    scanf("%256s", carros[i].nome);
    scanf("%d", &carros[i].ano);
    scanf("%256s", carros[i].cor);

    double preco;

    scanf("%lf", &preco);

    while (preco < 0.0) {
      printf("7: Preço inválido, tente novamente\n");
      scanf("%lf", &preco);
    }

    carros[i].preco = preco;
  }

  for (int i = 0; i < 50; i++) {
    if (strcmp(carros[i].cor, "azul") == 0 && carros[i].ano == 2017) {
      printf("Marca: %s Nome: %s Ano: %d Cor: %s Preco: R$ %.2lf\n",
             carros[i].marca, carros[i].nome, carros[i].ano, carros[i].cor,
             carros[i].preco);
    }
  }

  return 0;
}
