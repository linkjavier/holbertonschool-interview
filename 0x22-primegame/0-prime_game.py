#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """ Function that determine who is the winner of the game """

    if not nums or x < 1:
        return None

    n = max(nums)
    prime = [True for _ in range(max(n + 1, 2))]

    for i in range(2, int(pow(n, 0.5)) + 1):
        if not prime[i]:
            continue
        for j in range(i*i, n + 1, i):
            prime[j] = False

    prime[0] = prime[1] = False
    c = 0

    for i in range(len(prime)):
        if prime[i]:
            c += 1
        prime[i] = c

    first = 0

    for n in nums:
        first += prime[n] % 2 == 1
    if first * 2 == len(nums):
        return None
    if first * 2 > len(nums):
        return "Maria"
    return "Ben"
