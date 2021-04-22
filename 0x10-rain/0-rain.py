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

    for i in range(1, n - 1):
        # if (walls[i] > 0):
        #     rigthWallIndex = i
        #     break
        leftWallIndex = walls[i]
        for j in range(i):
            leftWallIndex = max(leftWallIndex, walls[j])
            # if (walls[j] > 0):
            #     leftWallIndex = j
            #     break
        rigthWallIndex = walls[i]

        for k in range(i + 1, n):
            rigthWallIndex = max(rigthWallIndex, walls[k])
            # if (walls[j] > 0):
            #     leftWallIndex = j
            #     break
        rainwater += min(leftWallIndex, rigthWallIndex) - walls[i]

    return rainwater
