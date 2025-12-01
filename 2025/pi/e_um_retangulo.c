#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool eRetangulo(int primeiro, int segundo, int terceiro, int quarto) {
  bool pstq = primeiro == segundo && terceiro == quarto;
  bool ptsq = primeiro == terceiro && segundo == quarto;
  bool pqst = primeiro == quarto && segundo == terceiro;

  if (pstq || ptsq || pqst) {
    return true;
  }

  return false;
}

int main() {
  // Entrada.
  int primeiro, segundo, terceiro, quarto;

  scanf("%d %d %d %d", &primeiro, &segundo, &terceiro, &quarto);

  if (eRetangulo(primeiro, segundo, terceiro, quarto)) {
    printf("RETANGULO\n");
  } else {
    printf("NAO EH UM RETANGULO\n");
  }

  exit(EXIT_SUCCESS);
}
