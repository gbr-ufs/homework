#include <iostream>

void merge(int *A, int p, int q, int r) {
  int n_L = q - p + 1;
  int n_R = r - q;
  int L[n_L];
  int R[n_R];

  for (int i = 0; i < n_L; i++) {
    L[i] = A[p + i];
  }

  for (int i = 0; i < n_R; i++) {
    R[i] = A[q + i + 1];
  }

  int i = 0;
  int j = 0;
  int k = p;

  while (i < n_L && j < n_R) {
    if (L[i] <= R[j]) {
      A[k++] = L[i++];
    } else {
      A[k++] = R[j++];
    }
  }

  while (i < n_L) {
    A[k++] = L[i++];
  }

  while (j < n_R) {
    A[k++] = R[j++];
  }
}

void merge_sort(int *A, int p, int r) {
  if (p >= r) {
    return;
  }

  int q = ((p + r) / 2);

  merge_sort(A, p, q);
  merge_sort(A, q + 1, r);
  merge(A, p, q, r);
}

int main() {
  int A[5] = {4, 3, 1, 6, 10};
  int n = sizeof(A) / sizeof(int);
  int p = 0;
  int r = 4;

  std::cout << "Unsorted." << '\n';

  for (int i = 0; i < n; i++) {
    std::cout << A[i] << '\n';
  }

  merge_sort(A, p, r);

  std::cout << "Sorted." << '\n';

  for (int i = 0; i < n; i++) {
    std::cout << A[i] << '\n';
  }

  return 0;
}
