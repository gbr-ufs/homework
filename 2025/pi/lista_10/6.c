#include <stdio.h>

struct aluno {
  char nome[257];
  long matricula;
  double notas[3];
  double total;
  double media;
};

int main() {
  struct aluno turma[30];
  int aprovados = 0;

  for (int i = 0; i < 30; i++) {
    scanf("%256s", turma[i].nome);
    scanf("%ld", &turma[i].matricula);
    turma[i].total = 0.0;
    for (int j = 0; j < 3; j++) {
      scanf("%lf", &turma[i].notas[j]);
      turma[i].total += turma[i].notas[j];
    }
    turma[i].media = turma[i].total / 3.0;
  }

  for (int i = 0; i < 30; i++) {
    if (turma[i].media > 7.0) {
      aprovados++;
    }
  }

  printf("%d\n", aprovados);

  return 0;
}
