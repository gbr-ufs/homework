#include <stdio.h>
#include <stdlib.h>

int main() {
  int horas;
  int horas_para_minutos;
  int minutos;
  int minutos_total;
  int segundos;

  scanf("%d %d", &horas, &minutos);
  horas_para_minutos = horas * 60;
  minutos_total = horas_para_minutos + minutos;
  segundos = minutos_total * 60;

  printf("%d\n", horas_para_minutos);
  printf("%d\n", horas_para_minutos + minutos_total);
  printf("%d\n", segundos);

  exit(EXIT_SUCCESS);
}
