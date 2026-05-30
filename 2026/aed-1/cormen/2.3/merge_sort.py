#!/usr/bin/env python3


def merge(A: list[int], p: int, q: int, r: int) -> None:
    n_L: int = q - p + 1
    n_R: int = r - q
    L: list[int] = [0] * (n_L + 1)
    R: list[int] = [0] * (n_R + 1)

    for i in range(n_L):
        L[i] = A[p + i]

    for i in range(n_R):
        R[i] = A[q + 1 + i]

    i: int = 0
    j: int = 0
    k: int = p

    while i < n_L and j < n_R:
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1

        else:
            A[k] = R[j]
            j = j + 1
        k = k + 1

    while i < n_L:
        A[k] = L[i]
        i = i + 1
        k = k + 1

    while j < n_R:
        A[k] = R[j]
        j = j + 1
        k = k + 1


def merge_sort(A: list[int], p: int, r: int) -> None:
    if p >= r:
        return

    q: int = (p + r) // 2

    merge_sort(A, p, q)
    merge_sort(A, q + 1, r)
    merge(A, p, q, r)


def main() -> None:
    A: list[int] = [4, 3, 1, 6, 10]
    n: int = len(A)
    p: int = 0
    r: int = 4

    print("Unsorted.")

    for i in range(n):
        print(A[i])

    merge_sort(A, p, r)

    print("Sorted.")

    for i in range(n):
        print(A[i])


if __name__ == "__main__":
    main()
