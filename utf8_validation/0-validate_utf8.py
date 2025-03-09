#!/usr/bin/python3
"""This module contains the function validUTF8."""


def validUTF8(data):
    """Checks if data set presents valid UTF_8 encoding."""
    bytes_number = 0
    for byte in data:
        byte = byte & 0xFF
        if bytes_number:
            if byte >> 6 != 0b10:
                return False
            bytes_number -= 1
        else:
            if byte >> 7 == 0:
                continue
            elif byte >> 5 == 0b110:
                bytes_number = 1
            elif byte >> 4 == 0b1110:
                bytes_number = 2
            elif byte >> 3 == 0b11110:
                bytes_number = 3
            else:
                return False
    return bytes_number == 0
