#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ Function that calculates how much water
        will be retained after it rains """
    n = len(walls)
    if n == 0:
        return 0

    # rigthWallIndex = 0
    # leftWallIndex = 0
    rainwater = 0

    for i in range(0, n):
        if (walls[i] > 0):
            rigthWallIndex = i
            break
    for j in reversed(range(0, n)):
        if (walls[j] > 0):
            leftWallIndex = j
            break
    for k in range(rigthWallIndex, leftWallIndex):
        if (walls[k] > 0):
            rainwater = rainwater + walls[k]

    return rainwater