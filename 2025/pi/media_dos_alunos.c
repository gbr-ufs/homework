#include <stdio.h>

int main() {
  // Entrada.
  double nota;
  // Saída.
  double soma = 0.0, media;

  for (int i = 0; i < 3; i++) {
    scanf("%lf", &nota);
    soma += nota;
  }
  media = soma / 3.0;

  if (media >= 3 && media < 7) {
    printf("prova final\n");
  } else if (media >= 7) {
    printf("aprovado\n");
  } else {
    printf("reprovado\n");
  }

  return 0;
}
