#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - recursive binary search,
 *@array: pointer to first element to array to be searched in
 * @left: first element of subarray being searched in
 * @right: last element of subarray being searched in
 * @value: value to be searched for in array
 * Return: index of value, -1 if value not found in array
 */
int binary_search(int *array, int left, int right, int value)
{
	if (left > right)
		return (-1);

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

	if (array[middle] == value && (middle == left || array[middle - 1] != value))
		return (middle);

	if (array[middle] < value)
	{
		return (binary_search(array, middle + 1, right, value));
	}
	else
	{
		return (binary_search(array, left, middle, value));
	}
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
