#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dimensões dos 3 lados
// informados em uma mesma linha, separados por espaço
// quando no lugar de três dimensões for encontrada a string FIM.

int maior_que_a_soma_dos_outros(int primeiro, int segundo, int terceiro) {
  int soma_ps = primeiro + segundo;
  int soma_pt = primeiro + terceiro;
  int soma_st = segundo + terceiro;

  if (primeiro < soma_st && segundo < soma_pt && terceiro < soma_ps) {
    return 1;
  }

  return 0;
}

int tres_iguais(int primeiro, int segundo, int terceiro) {
  if (primeiro == segundo && segundo == terceiro) {
    return 1;
  }

  return 0;
}

int todos_diferentes(int primeiro, int segundo, int terceiro) {
  if (primeiro != segundo && segundo != terceiro) {
    return 1;
  }

  return 0;
}

char *tipo_triangulo(int primeiro, int segundo, int terceiro) {
  int e_triangulo = maior_que_a_soma_dos_outros(primeiro, segundo, terceiro);

  if (!e_triangulo) {
    return "INVALIDO";
  }

  if (tres_iguais(primeiro, segundo, terceiro)) {
    return "EQUILATERO";
  } else if (todos_diferentes(primeiro, segundo, terceiro)) {
    return "ESCALENO";
  }

  return "ISOSCELES";
}

int main() {
  char entrada[513];
  int valores[3];
  int i = 0;

  scanf("%s", entrada);

  while (strcmp(entrada, "FIM")) {
    char *endptr;
    int valor = strtol(entrada, &endptr, 10);

    if (i < 3) {
      valores[i++] = valor;
    } else {
      printf("%s\n", tipo_triangulo(valores[0], valores[1], valores[2]));
      i = 0;
    }

    if (i != 3) {
      scanf("%s", entrada);
    }
  }

  exit(EXIT_SUCCESS);
}
