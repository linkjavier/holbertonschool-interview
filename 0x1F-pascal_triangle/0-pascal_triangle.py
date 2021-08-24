#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ Function that returns a list of lists of integers
        representing the Pascal’s triangle of n """

    pascal = []

    for i in range(n):
        actualNumber = [None for _ in range(i + 1)]
        actualNumber[0], actualNumber[-1] = 1, 1
        for j in range(1, len(actualNumber) - 1):
            actualNumber[j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
        pascal.append(actualNumber)

    return pascal
