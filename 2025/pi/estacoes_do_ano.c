#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct mes_estacao {
  char *marco, *junho, *setembro, *dezembro;
};

struct mes_estacao mes_estacao(char *marco, char *junho, char *setembro,
                               char *dezembro) {
  struct mes_estacao mes_estacao = {marco, junho, setembro, dezembro};

  return mes_estacao;
};

char const *EstacaoAno(int dia, int mes, struct mes_estacao *mes_estacao) {
  // Março, Junho, Setembro, Dezembro.
  int meses[4] = {3, 6, 9, 12};
  int dia_inicio = 21;
  int dia_fim = 20;

  if (mes >= meses[3] && dia >= dia_inicio ||
      mes <= meses[0] && dia <= dia_fim) {
    return mes_estacao->marco;
  }

  if (mes >= meses[0] && dia >= dia_inicio ||
      mes <= meses[1] && dia <= dia_fim) {
    return mes_estacao->junho;
  }

  if (mes >= meses[1] && dia >= dia_inicio ||
      mes <= meses[2] && dia <= dia_fim) {
    return mes_estacao->setembro;
  }

  if (mes >= meses[2] && dia >= dia_inicio ||
      mes <= meses[3] && dia <= dia_fim) {
    return mes_estacao->dezembro;
  }
}

int main() {
  // Entrada.
  int dia, mes;
  struct mes_estacao msts =
      mes_estacao("VERAO", "OUTONO", "INVERNO", "PRIMAVERA");

  scanf("%d %d", &dia, &mes);

  printf("%s\n", EstacaoAno(dia, mes, &msts));

  exit(EXIT_SUCCESS);
}
