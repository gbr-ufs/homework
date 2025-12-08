#include <stdio.h>
#include <stdlib.h>

// Serve para as questões 3 4 e 5.

int main() {
  char segundo;
  scanf("%c", &segundo);
  printf("%c\n", segundo);
  printf("%lu\n", sizeof(char));
  signed char terceiro;
  scanf("%c", &terceiro);
  printf("%c\n", terceiro);
  printf("%lu\n", sizeof(signed char));
  unsigned char quarto;
  scanf("%c", &quarto);
  printf("%c\n", quarto);
  printf("%lu\n", sizeof(unsigned char));
  short quinto;
  scanf("%hd", &quinto);
  printf("%hd\n", quinto);
  printf("%lu\n", sizeof(short));
  unsigned short sexto;
  scanf("%hu", &sexto);
  printf("%hu\n", sexto);
  printf("%lu\n", sizeof(unsigned short));
  int setimo;
  scanf("%d", &setimo);
  printf("%d\n", setimo);
  printf("%lu\n", sizeof(int));
  unsigned oitavo;
  scanf("%d", &oitavo);
  printf("%d\n", oitavo);
  printf("%lu\n", sizeof(unsigned));
  long nono;
  scanf("%ld", &nono);
  printf("%ld\n", nono);
  printf("%lu\n", sizeof(long));
  unsigned long decimo;
  scanf("%lu", &decimo);
  printf("%lu\n", decimo);
  printf("%lu\n", sizeof(unsigned long));
  long long decimo_primeiro;
  scanf("%lld", &decimo_primeiro);
  printf("%lld\n", decimo_primeiro);
  printf("%lu\n", sizeof(long long));
  unsigned long long decimo_segundo;
  scanf("%llu", &decimo_segundo);
  printf("%llu\n", decimo_segundo);
  printf("%lu\n", sizeof(unsigned long long));
  float decimo_terceiro;
  scanf("%f", &decimo_terceiro);
  printf("%0.2f\n", decimo_terceiro);
  printf("%lu\n", sizeof(float));
  double decimo_quarto;
  scanf("%lf", &decimo_quarto);
  printf("%0.2lf\n", decimo_quarto);
  printf("%lu\n", sizeof(double));
  long double decimo_quinto;
  scanf("%Lf", &decimo_quinto);
  printf("%0.2Lf\n", decimo_quinto);
  printf("%lu\n", sizeof(long double));

  exit(EXIT_SUCCESS);
}
