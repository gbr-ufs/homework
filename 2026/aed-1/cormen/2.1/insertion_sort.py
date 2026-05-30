#!/usr/bin/env python3


def insertion_sort(A: list[int], n: int) -> None:
    for i in range(n):
        key: int = A[i]
        j: int = i - 1

        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j = j - 1

        A[j + 1] = key


def main() -> None:
    A: list[int] = [4, 3, 1, 6, 10]
    n: int = len(A)

    print("Unsorted.")

    for i in range(n):
        print(A[i])

    insertion_sort(A, n)

    print("Sorted.")

    for i in range(n):
        print(A[i])


if __name__ == "__main__":
    main()
