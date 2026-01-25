#include <stdio.h>

int main() {
  char primeira[257];
  char segunda[257];

  scanf("%256s", primeira);
  scanf("%256s", segunda);

  int visto = 0;
  for (int i = 0; primeira[i] != '\0'; i++) {
    for (int j = 0; segunda[j]; j++) {
      if (primeira[i] == segunda[j]) {
        visto = 1;
      } else {
        visto = 0;
      }
    }
  }

  if (visto) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}
