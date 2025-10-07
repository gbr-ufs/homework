#include <stdio.h>
#include <stdlib.h>

int main() {
  float trabalho1, trabalho2, trabalho3, trabalho4 = 0.0;
  float nota_dos_trabalhos = 0.0;
  float seminario = 0.0;
  float prova1, prova2 = 0.0;
  float nota_das_provas = 0.0;
  float nota_final = 0.0;
  
  scanf("%f %f %f %f", &trabalho1, &trabalho2, &trabalho3, &trabalho4);
  scanf("%f", &seminario);
  scanf("%f %f", &prova1, &prova2);

  nota_dos_trabalhos = (trabalho1 + trabalho2 * 2 + trabalho3 * 3 + trabalho4 * 2) / 8;
  nota_das_provas = (prova1 * 4 + prova2 * 6) / 10;
  nota_final = (nota_dos_trabalhos * 4 + seminario * 2 + nota_das_provas * 4) / 10;

  printf("NT = %.2f\nNS = %.2f\nNP = %.2f\nNF = %.2f\n", nota_dos_trabalhos, seminario, nota_das_provas, nota_final);
        
  return EXIT_SUCCESS;
}
