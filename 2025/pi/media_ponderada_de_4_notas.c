#include <stdio.h>
#include <stdlib.h>

// length é o tamanho do array, calculado por sizeof(array) / sizeof(tipo).
// Os índices pares são os valores, e os ímpares são os pesos.
float MediaPonderada(float valor_peso[], int length) {
  // Soma com peso.
  float numerador = 0;
  // Soma dos pesos.
  float denominador = 0;

  for (int i = 0; i < length; i++) {
    if (i > 0 && i % 2 != 0) {
      continue;
    } else {
      numerador += valor_peso[i] * valor_peso[i + 1];
      denominador += valor_peso[i + 1];
    }
  }

  return numerador / denominador;
};

char *AnalisarSituacao(float primeira, float segunda, float terceira,
                       float quarta) {
  float primeira_peso = 1.0;
  float segunda_peso = 2.0;
  float terceira_peso = 3.0;
  float quarta_peso = 4.0;
  float valores[8] = {primeira, primeira_peso, segunda, segunda_peso,
                      terceira, terceira_peso, quarta,  quarta_peso};
  int length = sizeof(valores) / sizeof(float);
  float media = MediaPonderada(valores, length);

  if (media >= 9.0) {
    return "aprovado com louvor";
  } else if (media >= 7.0) {
    return "aprovado";
  } else if (media >= 3.0 && media < 7) {
    return "prova final";
  } else if (media < 3) {
    return "reprovado";
  }
}

int main() {
  float primeira, segunda, terceira, quarta;

  scanf("%f %f %f %f", &primeira, &segunda, &terceira, &quarta);

  printf("%s\n", AnalisarSituacao(primeira, segunda, terceira, quarta));

  exit(EXIT_SUCCESS);
}
