#!/usr/bin/python3
import sys

ResponsesCounter = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
counter = 0


def ShowStats():
    """
        Auxiliar function to Show Stats
    """
    global counter
    print('File size: {}'.format(counter))
    ResponsesCounteror = sorted(ResponsesCounter.keys())
    for each in ResponsesCounteror:
        if ResponsesCounter[each] > 0:
            print('{}: {}'.format(each, ResponsesCounter[each]))


if __name__ == "__main__":

    TenCounter = 0

    try:
        for data in sys.stdin:
            try:
                SplittedLine = data.split(' ')
                if SplittedLine[-2] in ResponsesCounter:
                    ResponsesCounter[SplittedLine[-2]] += 1
                counter += int(SplittedLine[-1])
            except BaseException:
                pass
            TenCounter += 1
            if TenCounter == 10:
                ShowStats()
                TenCounter = 0

    except KeyboardInterrupt:
        ShowStats()
        raise
    else:
        ShowStats()
