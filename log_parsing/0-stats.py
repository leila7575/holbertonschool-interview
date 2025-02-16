#!/usr/bin/python3
"""Reads stdin line by line and computes metrics."""

import sys

total_size = 0
status_codes = {200, 301, 400, 401, 403, 404, 405, 500}
status_code_number = {}
line_number = 0

def print_stats():
    """Prints statistics."""
    print(f"File size: {total_size}")
    for i in sorted(status_code_number.keys()):
        print(f"{i}: {status_code_number[i]}")

try:
    for line in sys.stdin:
        elements = line.split()


        if len(elements) < 7:
            continue

        try:
            file_size = int(elements[-1])
            status_code = int(elements[-2])
        except ValueError:
            continue 

        total_size += file_size

        if status_code in status_codes:
            status_code_number[status_code] = status_code_number.get(status_code, 0) + 1

        line_number += 1

        if line_number % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    pass

finally:
    print_stats()  
