#include <stdio.h>
#include <stdlib.h>

struct automovel {
  double v0, a, t, v;
};

double velkmh(double v0, double a, double t) {
  double taxa_ms_para_kmh = 3.6;
  double v = v0 + (a * t);

  return v * taxa_ms_para_kmh;
}

struct automovel automovel(double v0, double a, double t) {
  struct automovel automovel = {v0, a, t};

  return automovel;
}

double menor_de_3(double primeiro, double segundo, double terceiro) {
  if (primeiro <= segundo && primeiro <= terceiro) {
    return primeiro;
  } else if (segundo <= primeiro && segundo <= terceiro) {
    return segundo;
  } else {
    return terceiro;
  }
}

int main() {
  struct automovel primeiro, segundo, terceiro;

  scanf("%lf %lf %lf", &primeiro.v0, &primeiro.a, &primeiro.t);
  primeiro.v = velkmh(primeiro.v0, primeiro.a, primeiro.t);

  scanf("%lf %lf %lf", &segundo.v0, &segundo.a, &segundo.t);
  segundo.v = velkmh(segundo.v0, segundo.a, segundo.t);

  scanf("%lf %lf %lf", &terceiro.v0, &terceiro.a, &terceiro.t);
  terceiro.v = velkmh(terceiro.v0, terceiro.a, terceiro.t);

  printf("%0.1lf\n", menor_de_3(primeiro.v, segundo.v, terceiro.v));

  exit(EXIT_SUCCESS);
}
