#!/usr/bin/python3
"""Reads stdin line by line and computes metrics."""
import sys


total_size = 0
status_codes = {200, 301, 400, 401, 403, 404, 405, 500}
status_code_number = {}
line_number = 0

try:
    for line in sys.stdin:
        elements = line.split()

        file_size = int(elements[-1])
        status_code = int(elements[-2])

        total_size += file_size

        if status_code in status_codes:
            try:
                status_code_number[status_code] += 1
            except KeyError:
                status_code_number[status_code] = 1

        line_number += 1

        if line_number % 10 == 0:
            print(f"File size: {total_size}")
            for i in sorted(status_code_number.keys()):
                print(f"{i}: {status_code_number[i]}")

except KeyboardInterrupt:
    pass

finally:
    print(f"File size: {total_size}")
    for i in sorted_status_code:
        print(f"{i}: {status_code_number[status_code]}")
    raise
