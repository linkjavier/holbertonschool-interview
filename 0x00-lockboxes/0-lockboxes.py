#!/usr/bin/python3
""" Lockboxes """
from itertools import dropwhile


def canUnlockAll(boxes):
    """ Method that determines if all the boxes can be opened """

    BoxesNumber = len(boxes)
    keys = [0]
    for key in keys:
        UnitBox = boxes[key]
        for NewKey in UnitBox:
            if NewKey not in keys and NewKey < BoxesNumber:
                keys.append(NewKey)

    if BoxesNumber == len(keys):
        return True
    else:
        return False
