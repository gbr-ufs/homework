#include <stdio.h>
#include <stdlib.h>

char *intervalo(double entrada) {
  if (entrada < 0.0000 || entrada > 100.0000) {
    return "Fora de intervalo";
  } else if (entrada >= 0.0000 && entrada <= 25.0000) {
    return "[0,25]";
  } else if (entrada > 25.0000 && entrada <= 50.0000) {
    return "(25,50]";
  } else if (entrada > 50.0000 && entrada <= 75.0000) {
    return "(50,75]";
  }

  return "(75,100]";
}

int main() {
  double entrada;

  scanf("%lf", &entrada);

  printf("Intervalo %s\n", intervalo(entrada));

  exit(EXIT_SUCCESS);
}
