#!/usr/bin/python3
"""Minimum number of coins, greedy algorithm"""


def makeChange(coins, total):
    """Computes minimum number of coins needed to reach total"""
    number_coins = 0
    if total <= 0:
        return 0
    for coin in reversed(coins):
        while total >= coin:
            total -= coin
            number_coins += 1
    if total != 0:
        return -1
    return number_coins
