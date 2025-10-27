#include <stdio.h>

int bissexto(long ano) {
  if ((ano % 4 == 0 & ano % 100 != 0) || (ano % 400 == 0)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  long mes, ano;

  scanf("%ld %ld", &mes, &ano);
  // Janeiro, Março, Maio, Julho, Agosto, Outubro, Dezembro.
  if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 ||
      mes == 12) {
    printf("31\n");
  }
  // Fevereiro
  else if (mes == 2) {
    if (bissexto(ano)) {
      printf("29\n");
    } else {
      printf("28\n");
    }
  }
  // Abril, Junho, Setembro, Novembro.
  else {
    printf("30\n");
  }
  return 0;
}
