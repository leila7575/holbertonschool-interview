#!/usr/bin/python3
"""This module contains the function minOperations."""


def minOperations(n):
    """Calculates the minimum number of operations to obtain nH characters."""
    if n < 2:
        return 0
    prime_factors = []
    factor = 2
    while factor**2.0 <= n:
        while n % factor == 0:
            prime_factors.append(factor)
            n //= factor
        factor += 1
    if n > 1:
        prime_factors.append(n)
    return sum(prime_factors)
