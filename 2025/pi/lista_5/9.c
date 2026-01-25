#include <stdio.h>

int main() {
  int primeiro[5];
  int segundo[5];
  int intercalacao[10];

  for (int i = 0; i < 5; i++) {
    scanf("%d", &primeiro[i]);
  }

  for (int i = 0; i < 5; i++) {
    scanf("%d", &segundo[i]);
  }

  for (int i = 0; i < 10; i++) {
    int indice = i / 2;

    if (i % 2 == 0) {
      intercalacao[i] = primeiro[indice];
    } else {
      intercalacao[i] = segundo[indice];
    }
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", intercalacao[i]);
  }

  return 0;
}
