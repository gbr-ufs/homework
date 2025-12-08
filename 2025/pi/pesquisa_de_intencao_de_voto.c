#include <stdio.h>
#include <stdlib.h>

float vantagem(float candidato[], float concorrente[], int n) {
  float diferenca = 0.0;

  for (int i = 0; i < n; i++) {
    float diferenca_atual = candidato[i] - concorrente[i];

    if (diferenca_atual > diferenca) {
      diferenca = diferenca_atual;
    }
  }

  return diferenca;
}

int main() {
  int n;

  scanf("%d", &n);
  float candidato[n];
  float concorrente[n];

  for (int i = 0; i < n; i++) {
    scanf("%f", &candidato[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%f", &concorrente[i]);
  }

  printf("%0.2f\n", vantagem(candidato, concorrente, n));

  exit(EXIT_SUCCESS);
}
