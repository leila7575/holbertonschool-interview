#!/usr/bin/python3
"""pascal's triangle function"""


def pascal_triangle(n):
    """Returns list of lists integers representing pascal's triangle"""
    if n <= 0:
        return []

    pascal_triangle = []
    for nb_row in range(n):
        coeff = 1
        row = [coeff]
        for idx in range(1, nb_row + 1):
            coeff = coeff * (nb_row - idx + 1) // idx
            row.append(coeff)
        pascal_triangle.append(row)
    return pascal_triangle
