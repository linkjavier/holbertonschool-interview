#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """ Method that determines if a given data set
        represents a valid UTF-8 encoding
    """
    Checker = 0

    for element in data:
        if 191 >= element >= 128:
            if not Checker:
                return False
            Checker -= 1
        else:
            if Checker:
                return False
            if element < 128:
                continue
            elif element < 224:
                Checker = 1
            elif element < 240:
                Checker = 2
            elif element < 248:
                Checker = 3
            else:
                return False

    return Checker == 0
