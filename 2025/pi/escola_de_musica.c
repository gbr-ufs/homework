#include <stdio.h>
#include <stdlib.h>

// máximo 10 faltas.
// média mínima 7.
// não excede o limite de faltas e média superior a 9,5 é aprovado com louvor.

int main() {
  // Entrada.
  float media;
  int faltas;

  scanf("%f %d", &media, &faltas);

  if (faltas < 10 && media > 9.5) {
    printf("APROVADO COM LOUVOR\n");
  } else if (faltas <= 10 && media >= 7) {
    printf("APROVADO\n");
  } else if (faltas > 10) {
    printf("REPROVADO POR FALTAS\n");
  } else {
    printf("REPROVADO\n");
  }

  exit(EXIT_SUCCESS);
}
