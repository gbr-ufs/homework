#include <iostream>

int *add_binary_integers(int *A, int *B, int n) {
  int *C = (int *)malloc(n * sizeof(int));
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += A[i] * 1 << i;
    sum += B[i] * 1 << i;
  }

  for (int i = 0; sum != 0; i++) {
    C[i] = sum % 2;
    sum = sum / 2;
  }

  return C;
}

int main() {
  int A[5] = {1, 0, 0, 0, 0};
  int B[5] = {1, 1, 0, 0, 0};
  int n = 5;
  int *C = add_binary_integers(A, B, n);

  for (int i = 0; i < 5; i++) {
    std::cout << C[i] << '\n';
  }

  return 0;
}
