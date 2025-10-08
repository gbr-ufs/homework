#include <stdio.h>
#include <stdlib.h>

int soma_dos_quadrados(int n) {
  if (n == 0) {
    return n;
  } else {
    return (n * n) + soma_dos_quadrados(n - 1);
  }
}

int primeira_questao() {
  int n = 0;

  scanf("%d", &n);
  printf("%d\n\n", soma_dos_quadrados(n));
  
  return EXIT_SUCCESS;
}

int horario_para_segundo(int hora, int minuto) {
  return hora * 3600 + minuto * 60;
}

int segunda_questao() {
  int hora = 0;
  int minuto = 0;

  printf("Digite sua entrada no seguinte formato:\n");
  printf("\"XhYmin\", sendo X e Y inteiros positivos.\n");
  scanf("%dh%dmin", &hora, &minuto);
  printf("s = %d\n\n", horario_para_segundo(hora, minuto));

  return EXIT_SUCCESS;
}

int advinhador(char simbolo, int numero) {
  if (simbolo == '=') {
    printf("O numero secreto eh %d\n", numero);
    return EXIT_SUCCESS;
  }

  if (simbolo == '>') {
    printf("%d ?\n", numero + (numero / 2));
    scanf(" %c", &simbolo);
    advinhador(simbolo, numero + (numero / 2));
  } else if (simbolo == '<'){
    printf("%d ?\n", numero / 2);
    scanf(" %c", &simbolo);
    advinhador(simbolo, numero / 2);
  } else{
    perror("Caractere desconhecido\n");
  }
}

int desafio() {
  int numero_secreto = 0;
  char simbolo;

  scanf("%d", &numero_secreto);
  printf("500 ?\n");
  scanf(" %c", &simbolo);
  advinhador(simbolo, 500);
  
  return EXIT_SUCCESS;
}

int main() {
  int escolha;
  
  printf("Escolha a questão:\n");
  printf("[1]\n[2]\n[3] (Desafio)\n[4] Sair\n");
  scanf("%d", &escolha);

  switch (escolha) {
  case 1:
    primeira_questao();
    main();
  case 2:
    segunda_questao();
    main();
  case 3:
    desafio();
    main();
  case 4:
    return EXIT_SUCCESS;
  default:
    perror("Opção desconhecida\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
