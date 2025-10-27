#include <stdio.h>

int main() {
  // Entrada.
  double salario, percentual_de_aumento;
  // Saída.
  double valor_de_aumento;

  scanf("%lf %lf", &salario, &percentual_de_aumento);
  valor_de_aumento = salario * (percentual_de_aumento / 100);
  /* Usar "%%" escapa o "%", usado em C como especificador de formato.
   * Veja:
     <https://stackoverflow.com/questions/1860159/how-to-escape-the-percent-sign-in-cs-prinft>
   * Obrigado Paulo Santa Cruz
     <https://stackoverflow.com/users/67606/pablo-santa-cruz>.
   */
  printf("Seu salario teve aumento de %0.1lf %%, ", percentual_de_aumento);
  printf("passando de R$ %0.1lf ", salario);
  printf("para R$ %0.1lf\n", (salario + valor_de_aumento));

  return 0;
}
