#include <stdio.h>
#include <stdlib.h>

struct cadastro {
  char *nome;
  int idade;
  char *endereco;
};

int *criar_vetor(int n) { return calloc(n, sizeof(int)); }

int main() {
  int n;
  int *vetor;

  scanf("%d", &n);

  vetor = criar_vetor(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor[i]);
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", vetor[i]);
  }

  return 0;
}
