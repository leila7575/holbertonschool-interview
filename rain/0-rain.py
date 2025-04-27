#!/usr/bin/python3
"""
Contains function rain for units of water computation
"""


def rain(walls):
    """Computes number of units of water retained between two walls"""
    nb_walls = len(walls)

    if not walls or nb_walls < 3:
        return 0

    max_height_left = []
    for i in range(nb_walls):
        if i == 0:
            max_height_left.append(walls[0])
        else:
            max_height_left.append(max(max_height_left[i - 1], walls[i]))

    max_height_right = []
    for i in reversed(range(nb_walls)):
        if i == nb_walls - 1:
            max_height_right.append(walls[i])
        else:
            max_height_right.append(max(max_height_right[-1], walls[i]))
    max_height_right = list(reversed(max_height_right))

    water_units = 0
    for i in range(1, nb_walls - 1):
        water = min(max_height_left[i], max_height_right[i]) - walls[i]
        if water > 0:
            water_units += water

    return water_units
