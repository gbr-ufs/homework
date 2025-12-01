#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long maior_ab(long a, long b) { return (a + b + abs(a - b)) / 2; }

int main() {
  // Entrada.
  long primeiro, segundo, terceiro;
  // Saída.
  long resultado;
  long maior_primeiro_segundo;
  long maior_entre_todos;

  scanf("%ld %ld %ld", &primeiro, &segundo, &terceiro);

  maior_primeiro_segundo = maior_ab(primeiro, segundo);
  maior_entre_todos = maior_ab(maior_primeiro_segundo, terceiro);

  printf("%ld eh o maior\n", maior_entre_todos);

  exit(EXIT_SUCCESS);
}
