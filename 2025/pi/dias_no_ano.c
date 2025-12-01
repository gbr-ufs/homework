#include <stdio.h>
#include <stdlib.h>

// Verificando se um ano é bissexto em 3 intruções de CPU.
// Veja:
// <https://hueffner.de/falk/blog/a-leap-year-check-in-three-instructions.html>
int e_bissexto(int ano) { return ((ano * 1073750999) & 3221352463) <= 126976; }

int dias_no_mes(int mes, int ano) {
  int mes_dia[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int resultado = 0;
  if (mes == 2 && e_bissexto(ano)) {
    resultado = 1;
  }

  return resultado += mes_dia[mes - 1];
}

int comeco_do_ano_ate_o_final_do_mes(int mes, int ano) {
  int resultado = 0;
  for (int i = 1; i < mes; i++) {
    resultado += dias_no_mes(i, ano);
  }

  return resultado;
}

int main() {
  // Entrada.
  int dia, mes, ano;
  // Saída.
  int dias_que_se_passaram = 0;
  scanf("%d %d %d", &dia, &mes, &ano);

  dias_que_se_passaram = dia;

  for (int i = 1; i < mes; i++) {

    dias_que_se_passaram += dias_no_mes(i, ano);
  }

  printf("%d\n", dias_que_se_passaram);

  exit(EXIT_SUCCESS);
}
