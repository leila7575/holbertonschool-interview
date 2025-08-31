#!/usr/bin/python3
"""Determines the winner of the prime game"""


def prime_numbers(nums):
    """Determines all prime numbers in an interval"""
    booleans = []
    prime_nb_count = 0
    booleans = [True] * (nums + 1)
    for i in range(2, int(nums ** 0.5) + 1):
        if booleans[i]:
            for j in range(i * i, nums + 1, i):
                booleans[j] = False

    for i in range(2, nums):
        if booleans[i]:
            prime_nb_count += 1

    return prime_nb_count


def isWinner(x, nums):
    """Determines the winner of the prime game."""
    first_player_count = 0
    second_player_count = 0
    for i in nums:
        prime_nb_count = prime_numbers(i)
        if prime_nb_count % 2 == 0:
            second_player_count += 1
        else:
            first_player_count += 1

    if first_player_count > second_player_count:
        return 'Maria'
    elif second_player_count > first_player_count:
        return 'Ben'
    else:
        return None
