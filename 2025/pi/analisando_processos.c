#include <stdio.h>

int main() {
  // Entrada.
  int processos;
  // Saída.
  // 8 (horas) * 60 (minutos) = 480 (minutos).
  const int EXPEDIENTE = 480;

  scanf("%d", &processos);
  printf("%d\n", EXPEDIENTE / processos);

  return 0;
}
