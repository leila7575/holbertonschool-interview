#!/usr/bin/python3
"""This module contains the function minOperations."""


from sympy import factorint


def minOperations(n):
    """Calculates the minimum number of operations to obtain nH characters."""
    if n < 2:
        return 0

    operations = 0
    factors = factorint(n)
    for factor, exponent in factors.items():
        operations += factor * exponent
    return operations
