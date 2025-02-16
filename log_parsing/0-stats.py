#!/usr/bin/python3
"""Reads stdin line by line and computes metrics."""

import sys

if __name__ == "__main__":
    total_size = 0
    status_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    status_code_counts = {code: 0 for code in status_codes}
    line_number = 0

    try:
        for line in sys.stdin:
            elements = line.split()

            if len(elements) < 2:
                continue

            try:
                file_size = int(elements[-1])
                status_code = int(elements[-2])
            except ValueError:
                continue

            total_size += file_size

            if status_code in status_codes:
                status_code_counts[status_code] += 1

            line_number += 1

            if line_number % 10 == 0:
                print(f"File size: {total_size}")
                for code in sorted(status_code_counts.keys()):
                    if status_code_counts[code] > 0:
                        print(f"{code}: {status_code_counts[code]}")

    except KeyboardInterrupt:
        pass

    finally:
        print(f"File size: {total_size}")
        for code in sorted(status_code_counts.keys()):
            if status_code_counts[code] > 0:
                print(f"{code}: {status_code_counts[code]}")
