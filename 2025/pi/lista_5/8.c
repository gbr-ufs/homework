#include <stdio.h>
#include <stdlib.h>

int *uniao(int *x, int *y) {
  int *uni = calloc(20, sizeof(int));
  int uni_indice = 0;

  for (int i = 0; i < 10; i++) {
    uni[i] = x[i];
    uni_indice++;
  }

  for (int i = 0; i < 10; i++) {
    int visto = 0;

    for (int j = 0; j < uni_indice; j++) {
      if (uni[j] == y[i]) {
        visto = 1;
        break;
      }
    }

    if (!visto) {
      uni[uni_indice] = y[i];
      uni_indice++;
    }
  }

  return uni;
}

int *diferenca(int *x, int *y) {
  int *diff = calloc(10, sizeof(int));
  int diff_indice = 0;

  for (int i = 0; i < 10; i++) {
    int visto = 0;

    for (int j = 0; j < 10; j++) {
      if (x[i] == y[j]) {
        visto = 1;
        break;
      }
    }

    if (!visto) {
      diff[diff_indice] = x[i];
      diff_indice++;
    }
  }

  return diff;
}

int *intersecao(int *x, int *y) {
  int *inter = calloc(10, sizeof(int));
  int inter_indice = 0;

  for (int i = 0; i < 10; i++) {
    int dentro = 0;

    for (int j = 0; j < inter_indice; j++) {
      if (x[i] == inter[j]) {
        dentro = 1;
        break;
      }
    }

    if (dentro) {
      continue;
    }

    int visto = 0;

    for (int j = 0; j < 10; j++) {
      if (x[i] == y[j]) {
        visto = 1;
        break;
      }
    }

    if (visto) {
      inter[inter_indice] = x[i];
      inter_indice++;
    }
  }

  return inter;
}

int main() {
  int x[10];
  int y[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &x[i]);
  }

  for (int i = 0; i < 10; i++) {
    scanf("%d", &y[i]);
  }

  int *uni = uniao(x, y);
  int *diff = diferenca(x, y);
  int *inter = intersecao(x, y);

  printf("união\n");
  for (int i = 0; i < 20; i++) {
    printf("%d\n", uni[i]);
  }

  printf("diferença\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", diff[i]);
  }

  printf("interseção\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", inter[i]);
  }

  return 0;
}
