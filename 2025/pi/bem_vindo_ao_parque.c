#include <stdio.h>

int main() {
  // Entrada.
  char nome[65], atracao[257];

  // "[^\n]" significa tudo MENOS a quebra de linha. Acho que é uma regexp.
  scanf("%[^\n] %[^\n]", nome, atracao);
  printf("Bem-vindo %s! Aguardamos você na/o %s!\n", nome, atracao);

  return 0;
}
