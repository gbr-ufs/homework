#!/usr/bin/env python


def add_binary_integers(A: list[int], B: list[int], n: int) -> list[int]:
    C: list[int] = [0] * (n + 1)
    sum: int = 0

    for i in range(n):
        sum += A[i] * 1 << i
        sum += B[i] * 1 << i

    i: int = 0

    while sum != 0:
        C[i] = sum % 2
        sum //= 2
        i += 1

    return C


def main() -> None:
    A: list[int] = [1, 0, 0, 0, 0]
    B: list[int] = [1, 1, 0, 0, 0]
    n: int = 5
    C: list[int] = add_binary_integers(A, B, n)

    for i in range(n):
        print(C[i])


if __name__ == "__main__":
    main()
