#include <stdio.h>
#include <stdlib.h>

char *determinar_profissao(int personagem[5]) {
  int knight_ou_paladin_ou_orc = 0;

  if (personagem[0] > 5) {
    knight_ou_paladin_ou_orc = 1;
  }

  if (knight_ou_paladin_ou_orc) {
    if (personagem[0] > 10 && personagem[2] < 5) {
      return "Orc";
    } else if (personagem[4] > 5) {
      return "Knight";
    } else {
      return "Paladin";
    }
  }

  return "Mage";
}

int main() {
  int personagem[5];

  for (int i = 0; i < 5; i++) {
    scanf("%d", &personagem[i]);
  }

  printf("%s\n", determinar_profissao(personagem));

  exit(EXIT_SUCCESS);
}
