#include <stdio.h>

double volume(double a) { return a * a * a; }

int main() {
  double a;
  double vol;

  scanf("%lf", &a);

  vol = volume(a);

  printf("%lf\n", vol);

  return 0;
}
