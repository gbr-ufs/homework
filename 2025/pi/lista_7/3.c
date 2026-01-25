#include <stdio.h>

void trocar_valor(double *primeiro, double *segundo) {
  double tmp = *primeiro;
  *primeiro = *segundo;
  *segundo = tmp;
}

int main() {
  double primeiro;
  double segundo;

  scanf("%lf", &primeiro);
  scanf("%lf", &segundo);

  printf("primeiro: %lf\n", primeiro);
  printf("segundo: %lf\n", segundo);

  trocar_valor(&primeiro, &segundo);

  printf("primeiro: %lf\n", primeiro);
  printf("segundo: %lf\n", segundo);

  return 0;
}
