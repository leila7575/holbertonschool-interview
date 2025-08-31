#!/usr/bin/python3
"""Determines the winner of the prime game"""


def prime_numbers(n):
    """
    Returns an array of prime numbers.
    """
    is_prime = [False, False] + [True] * (n - 1)
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    prime_count = [0] * (n + 1)
    for i in range(1, n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if is_prime[i] else 0)
    return prime_count


def isWinner(x, nums):
    """
    Determines the winner of the prime game.
    """
    if not nums or x < 1:
        return None
    n = max(nums)
    prime_count = prime_numbers(n)
    maria_wins = 0
    ben_wins = 0
    for num in nums:
        if prime_count[num] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
