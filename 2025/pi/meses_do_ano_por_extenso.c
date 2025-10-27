#include <stdio.h>
#include <stdlib.h>

int main() {
  int ano;

  scanf("%d", &ano);

  if (ano < 1 || ano > 12) {
    printf("invalido\n");
    exit(EXIT_FAILURE);
  }

  /*
   * Kalil não gosta de switch, mas C não possui alists ou hashmaps, então
   * usamos vários ifs mesmo.
   */
  if (ano == 1) {
    printf("janeiro\n");
  } else if (ano == 2) {
    printf("fevereiro\n");
  } else if (ano == 3) {
    printf("marco\n");
  } else if (ano == 4) {
    printf("abril\n");
  } else if (ano == 5) {
    printf("maio\n");
  } else if (ano == 6) {
    printf("junho\n");
  } else if (ano == 7) {
    printf("julho\n");
  } else if (ano == 8) {
    printf("agosto\n");
  } else if (ano == 9) {
    printf("setembro\n");
  } else if (ano == 10) {
    printf("outubro\n");
  } else if (ano == 11) {
    printf("novembro\n");
  } else if (ano == 12) {
    printf("dezembro\n");
  }

  return 0;
}
