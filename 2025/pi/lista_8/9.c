#include <stdio.h>

// Soma fechada.
int soma_entre(int primeiro, int segundo) {
  if (primeiro > segundo) {
    return 0;
  }

  return primeiro + soma_entre(primeiro + 1, segundo);
}

int main() {
  int primeiro;
  int segundo;
  int soma;

  scanf("%d", &primeiro);
  scanf("%d", &segundo);

  if (primeiro > segundo) {
    int tmp = primeiro;
    primeiro = segundo;
    segundo = tmp;
  }

  soma = soma_entre(primeiro, segundo);

  printf("%d\n", soma);

  return 0;
}
