#!/usr/bin/env python3


def insertion_sort(a: list[int], n: int) -> None:
    for i, _ in enumerate(a):
        key: int = a[i]
        j: int = i - 1
        while j >= 0 and a[j] < key:
            a[j + 1] = a[j]
            j = j - 1
        a[j + 1] = key


def main() -> None:
    a: list[int] = [4, 3, 1, 6, 10]
    n: int = a.__len__()

    print("Unsorted.")

    for i, _ in enumerate(a):
        print(a[i])

    insertion_sort(a, n)

    print("Sorted.")

    for i, _ in enumerate(a):
        print(a[i])


if __name__ == "__main__":
    main()
