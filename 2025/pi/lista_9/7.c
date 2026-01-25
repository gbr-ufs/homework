#include <stdio.h>

struct aluno {
  long matricula;
  char *nome;
  float notas[3];
};

int main() {
  struct aluno al = {197000051321, "Foo", {10.0, 9.0, 10.0}};

  printf("%ld\n", sizeof(al));

  return 0;
}
