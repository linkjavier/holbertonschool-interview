#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ Function that returns a list of lists of integers
        representing the Pascal’s triangle of n """

    pascal = []
    if n == 1:
        return [1]

    else:
        for i in range(n):
            newElement = [1]
            if pascal:
                last = pascal[-1]
                newElement.extend([sum(pair) for pair in zip(last, last[1:])])
                newElement.append(1)
            pascal.append(newElement)

    return(pascal)
