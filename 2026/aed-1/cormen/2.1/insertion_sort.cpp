#include <iostream>

void insertion_sort(int *A, int n) {
  for (int i = 1; i < n; i++) {
    int key = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j = j - 1;
    }

    A[j + 1] = key;
  }
}

int main() {
  int A[5] = {4, 3, 1, 6, 10};
  int n = sizeof(A) / sizeof(int);

  std::cout << "Unsorted." << '\n';

  for (int i = 0; i < n; i++) {
    std::cout << A[i] << '\n';
  }

  insertion_sort(A, n);

  std::cout << "Sorted." << '\n';

  for (int i = 0; i < n; i++) {
    std::cout << A[i] << '\n';
  }

  return 0;
}
