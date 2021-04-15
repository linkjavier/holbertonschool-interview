#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ Function that calculates how much water
        will be retained after it rains """
    n = len(walls)
    if n == 0:
        return 0

    rainwater = 0
    i = 0
    for i in range(i+1, n - 2):
        if (walls[i] != 0):
            rainwater = rainwater + walls[i]

    return rainwater
