#include <stdio.h>

int main() {
  int primeiro[10];
  int segundo[10];
  int soma[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &primeiro[i]);
  }

  for (int i = 0; i < 10; i++) {
    scanf("%d", &segundo[i]);
    soma[i] = primeiro[i] + segundo[i];
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", soma[i]);
  }

  return 0;
}
