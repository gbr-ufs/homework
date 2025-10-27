#include <stdio.h>

int intervalo(double inicio, double valor, double fim) {
  if (valor <= inicio && valor >= fim) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  // Entrada.
  long quantidade_de_livros, quantidade_de_alunos;
  // Saída.
  double escala_livro_aluno;
  double conceito_a = 1.0 / 8.0;
  double conceito_b_inicio = 1.0 / 9.0, conceito_b_fim = 1.0 / 12.0;
  double conceito_c_inicio = 1.0 / 13.0, conceito_c_fim = 1.0 / 18.0;

  scanf("%ld %ld", &quantidade_de_livros, &quantidade_de_alunos);
  escala_livro_aluno =
      (double)quantidade_de_livros / (double)quantidade_de_alunos;

  if (escala_livro_aluno >= conceito_a) {
    printf("A\n");
  } else if (intervalo(conceito_b_inicio, escala_livro_aluno, conceito_b_fim)) {
    printf("B\n");
  } else if (intervalo(conceito_c_inicio, escala_livro_aluno, conceito_c_fim)) {
    printf("C\n");
  } else {
    printf("D\n");
  }

  return 0;
}
