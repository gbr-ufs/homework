#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *numero_para_dia(int dia) {
  switch (dia) {
  case 1:
    return "Domingo";
  case 2:
    return "Segunda";
  case 3:
    return "Terça";
  case 4:
    return "Quarta";
  case 5:
    return "Quinta";
  case 6:
    return "Sexta";
  case 7:
    return "Sábado";
  default:
    return "Inválido";
  }
}

int main() {
  int dia;
  char *resultado;

  scanf("%d", &dia);
  resultado = numero_para_dia(dia);

  if (strcmp(resultado, "Inválido")) {
    printf("%s\n", resultado);
  }

  exit(EXIT_SUCCESS);
}
