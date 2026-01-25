#include <stdio.h>

int main() {
  char string[11];
  char caractere_para_busca;
  int contagem = 0;

  scanf("%s", string);
  printf("Escolha o caráctere para busca: ");
  scanf(" %c", &caractere_para_busca);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == caractere_para_busca) {
      contagem++;
    }
  }

  printf("%d\n", contagem);

  return 0;
}
