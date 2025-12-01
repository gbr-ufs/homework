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

char const *EstacaoAnoNorte(int dia, int mes) {
  struct mes_estacao norte =
      mes_estacao("INVERNO", "PRIMAVERA", "VERAO", "OUTONO");

  return EstacaoAno(dia, mes, &norte);
}

char const *EstacaoAnoSul(int dia, int mes) {
  struct mes_estacao sul =
      mes_estacao("VERAO", "OUTONO", "INVERNO", "PRIMAVERA");

  return EstacaoAno(dia, mes, &sul);
}

int main() {
  // Entrada.
  int dia, mes, hemisferio;

  scanf("%d %d %d", &hemisferio, &dia, &mes);

  if (hemisferio == 0) {
    printf("%s\n", EstacaoAnoNorte(dia, mes));
  } else {
    printf("%s\n", EstacaoAnoSul(dia, mes));
  }

  exit(EXIT_SUCCESS);
}
