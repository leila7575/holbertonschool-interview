#!/usr/bin/python3
"""Returns the perimeter of the island"""


def island_perimeter(grid):
    """Returns the perimeter of the island based on the grid"""
    rows_number = len(grid)
    columns_number = len(grid[0])
    res = 0
    for i in range(rows_number):
        for j in range(columns_number):
            if grid[i][j] == 1:
                res += 4
                if i < rows_number - 1 and grid[i + 1][j] == 1:
                    res -= 2
                if j < columns_number - 1 and grid[i][j + 1] == 1:
                    res -= 2

    return res
