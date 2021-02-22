#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """ Method that determines if a given data set
        represents a valid UTF-8 encoding
    """

    Checker = 0
    for element in data:
        BinaryElement = format(element, '#010b')[-8:]
        if Checker == 0:
            for unit in BinaryElement:
                if unit == '0':
                    break
                Checker += 1
            if Checker == 0:
                continue
            if Checker == 1 or Checker > 4:
                return False
        else:
            if not (BinaryElement[0] == '1' and BinaryElement[1] == '0'):
                return False
        Checker -= 1
    return Checker == 0
