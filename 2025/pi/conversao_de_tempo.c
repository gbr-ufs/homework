#include <stdio.h>
#include <stdlib.h>

int main() {
  const long SEGUNDOS_EM_HORA = 3600, SEGUNDOS_EM_MINUTO = 60;
  // Entrada.
  long segundos;
  // Saída.
  long horas_formatadas, minutos_formatados, segundos_formatados;
  long resto_horas, resto_minutos;

  scanf("%ld", &segundos);
  horas_formatadas = (long)(segundos / SEGUNDOS_EM_HORA);
  resto_horas = segundos % SEGUNDOS_EM_HORA;
  minutos_formatados = (long)(resto_horas / SEGUNDOS_EM_MINUTO);
  resto_minutos = resto_horas % SEGUNDOS_EM_MINUTO;
  segundos_formatados = resto_minutos;
  printf("%ld:%ld:%ld\n", horas_formatadas, minutos_formatados,
         segundos_formatados);

  return 0;
}
