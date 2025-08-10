#!/usr/bin/python3
"""pascal's triangle function"""


from math import factorial


def pascal_triangle(n):
    """Returns list of lists integers representing pascal's triangle"""
    if n <= 0:
        return []

    pascal_triangle = []
    for nb_row in range(n):
        row = []
        for idx in range(nb_row + 1):
            row.append(
                factorial(nb_row) // (factorial(idx) * factorial(nb_row - idx))
            )
        pascal_triangle.append(row)
    return pascal_triangle
