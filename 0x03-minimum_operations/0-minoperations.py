#!/usr/bin/python3
"""minOperations python program"""


def minOperations(n):
    """
        Method that calculates the fewest number of operations
        needed to result in exactly n H characters in the file.
    """

    divisor = 2
    fewestOperations = 0

    if not isinstance(n, int) or n <= 1:
        return 0

    while n != 1:
        if n % divisor == 0:
            n = n / divisor
            fewestOperations = fewestOperations + divisor
        else:
            divisor = divisor + 1

    return fewestOperations
