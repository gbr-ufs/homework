#include <stdio.h>

int intervalo(long inicio, long valor, long fim) {
  if (valor >= inicio && valor <= fim) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  // Entrada.
  long idade;
  // Saída
  long infantil_a_inicio = 5, infantil_a_fim = 7;
  long infantil_b_inicio = 8, infantil_b_fim = 10;
  long juvenil_a_inicio = 11, juvenil_a_fim = 13;
  long juvenil_b_inicio = 14, juvenil_b_fim = 17;
  long adulto_inicio = 18, adulto_fim = 40;

  scanf("%ld", &idade);
  if (idade < 0) {
    printf("Idade invalida.\n");

    return 0;
  }
  if (intervalo(infantil_a_inicio, idade, infantil_a_fim)) {
    printf("Infantil A\n");
  } else if (intervalo(infantil_b_inicio, idade, infantil_b_fim)) {
    printf("Infantil B\n");
  } else if (intervalo(juvenil_a_inicio, idade, juvenil_a_fim)) {
    printf("Juvenil A\n");
  } else if (intervalo(juvenil_b_inicio, idade, juvenil_b_fim)) {
    printf("Juvenil B\n");
  } else if (intervalo(adulto_inicio, idade, adulto_fim)) {
    printf("Adulto\n");
  } else {
    printf("Master\n");
  }

  return 0;
}
