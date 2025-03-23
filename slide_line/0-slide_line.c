#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * reverse_array -reverses array
 * @line: Pointer to the array of integer
 * @size: Number of elements to be slided and merged
 * @direction: sliding and merging direction slide_left or slide_right
 * Returns: 1 on success, 0 on failure
 */
void reverse_array(int *line, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: Pointer to the array of integer
 * @size: Number of elements to be slided and merged
 * @direction: sliding and merging direction slide_left or slide_right
 * Returns: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		reverse_array(line, size);
	}

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
				line[j] = line[i];
			if (j > 0 && line[j] == line[j - 1])
			{
				line[j - 1] *= 2;
				line[j] = 0;
				j--;
			}
			j++;
		}
	}
	for (; j < size; j++)
	{
		line[j] = 0;
	}

	if (direction == SLIDE_RIGHT)
	{
		reverse_array(line, size);
	}
	return (1);
}
