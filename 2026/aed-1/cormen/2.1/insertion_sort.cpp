#include <iostream>

void insertion_sort(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j = j - 1;
    }

    a[j + 1] = key;
  }
}

int main() {
  int a[5] = {4, 3, 1, 6, 10};
  int n = sizeof(a) / sizeof(int);

  std::cout << "Unsorted." << '\n';

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << '\n';
  }

  insertion_sort(a, n);

  std::cout << "Sorted." << '\n';

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << '\n';
  }

  return 0;
}
