#include <stdio.h>
#include <stdlib.h>

int main() {
  float dias[7];
  float total = 0.0, media = 0.0, melhor = 0.0;

  for (int i = 0; i < 7; i++) {
    scanf("%f", &dias[i]);
    float valor_atual = dias[i];

    total += valor_atual;
    if (valor_atual > melhor) {
      melhor = valor_atual;
    }
  }

  media = total / 7;

  printf("--- Relatório de Vendas da Semana ---\n");
  printf("Venda Total: R$ %.2f\n", total);
  printf("Média Diária: R$ %.2f\n", media);
  printf("Melhor Venda: R$ %.2f\n", melhor);

  exit(EXIT_SUCCESS);
}
