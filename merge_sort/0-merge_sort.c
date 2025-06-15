#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merge sort algorithm, sorts two subarrays
 * @array: array to be sorted
 * @temp: temporary array
 * @left: left index
 * @right: right index
 * @middle: middle index
 */
void merge(int *array, int *temp, size_t left, size_t middle, size_t right)
{
	size_t left_idx = left, right_idx = middle + 1, temp_idx = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left + 1);
	printf("[right]: ");
	print_array(array + middle + 1, right - middle);

	for (size_t i = left; i <= right; i++)
		temp[i] = array[i];

	while (left_idx <= middle && right_idx <= right)
	{
		if (temp[left_idx] <= temp[right_idx])
			array[temp_idx++] = temp[left_idx++];
		else
			array[temp_idx++] = temp[right_idx++];
	}

	while (left_idx <= middle)
	{
		array[temp_idx++] = temp[left_idx++];
	}

	while (right_idx <= right)
	{
		array[temp_idx++] = temp[right_idx++];
	}

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_subarray - merge sort algorithm, sorts subarrrays
 * @array: array to be sorted
 * @temp: temporary array
 * @left: left index
 * @right: right index
 */
void merge_sort_subarray(int *array, int *temp, int left, int right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		merge_sort_subarray(array, temp, left, middle);
		merge_sort_subarray(array, temp, middle + 1, right);
		merge(array, temp, left, middle, right);
	}
}


/**
 * merge_sort - sorts array in ascending order with merge sort algorithm
 * @array: array to be sorted
 *	@size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);

	merge_sort_subarray(array, temp, 0, size - 1);
	free(temp);
}
