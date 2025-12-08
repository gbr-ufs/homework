#include <stdio.h>
#include <stdlib.h>

int main() {
  int idade;
  char *resultado;

  scanf("%d", &idade);

  if (idade < 0) {
    printf("Inválido\n");

    exit(EXIT_FAILURE);
  }

  if (idade > 45) {
    resultado = "Sênior";
  } else if (idade > 30) {
    resultado = "Adulto";
  } else if (idade > 15) {
    resultado = "Adolescente";
  } else if (idade > 10) {
    resultado = "Jovem";
  } else {
    resultado = "Criança";
  }

  printf("%s\n", resultado);

  exit(EXIT_SUCCESS);
}
