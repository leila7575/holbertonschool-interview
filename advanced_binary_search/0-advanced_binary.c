#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - recursive binary search,
 * searches for value and returns its index in sorted array of integers
 *@array: pointer to first element to array to be searched in
 * @left: first element of subarray being searched in
 * @right: last element of subarray being searched in
 * @value: value to be searched for in array
 */
int binary_search(int *array, int left, int right, int value)
{
	if (right >= left)
	{
		int middle = left + (right - left) / 2;

		printf("Searching in array: ");
		for (int i = left; i <= right; i++)
		{
			if (i == left)
				printf("%d", array[i]);
			else
				printf(", %d", array[i]);
		}
		printf("\n");

		if (array[middle] == value)
		{
			if (middle == left || array[middle - 1] != value)
				return (middle);
			else
				return (binary_search(array, left, middle, value));
		}
		else if (array[middle] > value)
		{
			return (binary_search(array, left, middle - 1, value));
		}
		else
		{
			return (binary_search(array, middle + 1, right, value));
		}
	}
	return (-1);
}

/**
 * advanced_binary - recursive binary search,
 * searches for value and returns its index in sorted array of integers
 *@array: pointer to first element t array to be searched in
 * @size: number of elements in array
 * @value: value to be searched for in array
 * Return: index of value if value present in array, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (binary_search(array, 0, (int)size - 1, value));
}
