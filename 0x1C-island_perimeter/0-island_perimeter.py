#!/usr/bin/python3
""" Island Perimeter """


def island_perimeter(grid):
    """Function that returns the perimeter of the island described in grid"""
    rows = len(grid)
    columns = len(grid[0])
    plus = 0
    landing = 0

    for col in range(rows):
        plus += sum(grid[col])
        for row in range(columns):
            if grid[col][row]:
                if row > 0 and grid[col][row - 1] == 1:
                    landing += 1

                if col > 0 and grid[col - 1][row] == 1:
                    landing += 1
    return plus * 4 - landing * 2
