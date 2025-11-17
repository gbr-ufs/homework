#include <stdio.h>

int main() {
  // Entrada.
  long quantidade_de_livros, quantidade_de_alunos;
  // Saída.
  double escala_livro_aluno;
  long conceito_a = 8;
  long conceito_b = 12;
  long conceito_c = 18;

  scanf("%ld %ld", &quantidade_de_alunos, &quantidade_de_livros);
  escala_livro_aluno =
      (double)quantidade_de_alunos / (double)quantidade_de_livros;

  if (escala_livro_aluno <= conceito_a) {
    printf("A\n");
  } else if (escala_livro_aluno <= conceito_b) {
    printf("B\n");
  } else if (escala_livro_aluno <= conceito_c) {
    printf("C\n");
  } else {
    printf("D\n");
  }

  return 0;
}
