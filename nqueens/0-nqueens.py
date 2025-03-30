#!/usr/bin/python3
"""Prints all solutions of the N queens challenge."""


import sys


def checkColDiags(board, row, column, N):
    """Checks if a queen can be safely placed."""
    for i in range(row):
        if board[i] == column:
            return False

    for i in range(row - 1, -1, -1):
        j = column - (row - i)
        if j >= 0 and board[i] == j:
            return False

    for i in range(row - 1, -1, -1):
        j = column + (row - i)
        if j < N and board[i] == j:
            return False

    return True


def queenPlacements(row, board, N, positions):
    """Finds all queen positions."""
    if row == N:
        positions.append([[i, board[i]] for i in range(N)])
        return

    for column in range(N):
        if checkColDiags(board, row, column, N):
            board[row] = column
            queenPlacements(row + 1, board, N, positions)


def nQueens(N):
    """Prints all solutions for the N-queens problem."""
    board = [-1] * N
    positions = []
    queenPlacements(0, board, N, positions)

    for position in positions:
        print(position)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    nQueens(N)
