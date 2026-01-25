#include <stdio.h>
#include <string.h>

struct livro {
  char titulo[257];
  char autor[257];
  char estilo[257];
  char isbn[14];
  double preco;
};

int main() {
  struct livro livraria[100];
  double soma = 0.0;
  double media;

  for (int i = 0; i < 100; i++) {
    scanf("%256s", livraria[i].titulo);
    scanf("%256s", livraria[i].autor);
    scanf("%256s", livraria[i].estilo);
    scanf("%14s", livraria[i].isbn);

    double preco;

    scanf("%lf", &preco);

    while (preco < 0.0) {
      printf("8: Valor inválido, tente novamente\n");
      scanf("%lf", &preco);
    }

    livraria[i].preco = preco;
    soma += preco;
  }

  media = soma / 100.0;

  printf("Média dos preços: R$ %.2lf\n", media);

  for (int i = 0; i < 100; i++) {
    if (strcmp(livraria[i].estilo, "terror") == 0) {
      printf("Título: %s Autor: %s ISBN: %s Preço: R$ %.2lf\n",
             livraria[i].titulo, livraria[i].autor, livraria[i].isbn,
             livraria[i].preco);
    }
  }

  return 0;
}
