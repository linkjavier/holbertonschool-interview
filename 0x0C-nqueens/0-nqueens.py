#!/usr/bin/python3
""" N Queens """
import sys

if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)
try:
    N = int(sys.argv[1])
except Exception:
    print('N must be a number')
    exit(1)
if N < 4:
    print('N must be at least 4')
    exit(1)

queens = []


def Nqueens(n):
    """ Program that solvess the N queens problem """

    for i in range(N):
        if queens == []:
            queens.append([n, i])
            Nqueens(n + 1)
            queens.pop()
        else:
            auxiliar = [
                i == e[1] or abs(
                    n -
                    e[0]) == abs(
                    i -
                    e[1]) for e in queens]
            if not any(auxiliar):
                queens.append([n, i])
                if n == N - 1:
                    print(queens)
                else:
                    Nqueens(n + 1)
                queens.pop()


Nqueens(0)
