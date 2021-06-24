def quicksort(array):
    """ Function to sort an array using descending quicksort """

    greater = []
    equal = []
    less = []

    if len(array) > 1:
        pivot = array[0]
        for x in array:
            if x > pivot:
                greater.append(x)
            elif x == pivot:
                equal.append(x)
            elif x < pivot:
                less.append(x)

        return quicksort(greater) + equal + quicksort(less)

    else:
        return array


def makeChange(coins, total):
    """ Function that determines the fewest number of coins needed
        to meet a given amount total
    """

    if total <= 0:
        return 0

    SortedCoins = quicksort(coins)
    SubTotal = 0
    FewestCoins = 0

    for coin in SortedCoins:
        while (SubTotal + coin <= total):
            SubTotal += coin
            FewestCoins += 1

    if SubTotal != total:
        return (-1)

    return (FewestCoins)
