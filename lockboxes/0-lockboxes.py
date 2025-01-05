#!/usr/bin/python3
"""This module contains the function canUnlockAll."""


def canUnlockAll(boxes):
    """Determines if all boxes can be unlocked."""
    keylist = [0]
    for box in keylist:
        for key in boxes[box]:
            if key not in keylist:
                keylist.append(key)

    return all(index in keylist for index in range(len(boxes)))
