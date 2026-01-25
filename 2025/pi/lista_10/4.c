#include <stdio.h>

struct aluno {
  char nome[257];
  long matricula;
  double notas[2];
  double total;
  double media;
};

int main() {
  struct aluno turma[50];
  int aprovados = 0;

  for (int i = 0; i < 50; i++) {
    scanf("%256s", turma[i].nome);
    scanf("%ld", &turma[i].matricula);
    turma[i].total = 0.0;
    for (int j = 0; j < 2; j++) {
      scanf("%lf", &turma[i].notas[j]);
      turma[i].total += turma[i].notas[j];
    }
    turma[i].media = turma[i].total / 2.0;
  }

  for (int i = 0; i < 50; i++) {
    if (turma[i].media > 5.0) {
      aprovados++;
    }
  }

  printf("%d\n", aprovados);

  return 0;
}
