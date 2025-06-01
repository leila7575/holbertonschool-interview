#!/usr/bin/python3
"""Contains rotate_2d_matrix(matrix)"""


def rotate_2d_matrix(matrix):
    """Rotates 2D matrix clockwise"""
    n = len(matrix)

    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for row in matrix:
        row.reverse()
