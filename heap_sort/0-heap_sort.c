#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * heapify - Sorts array of integers with Heap Sort algorithm
 *
 * @array: array representing heap
 * @size: number of elements
 * @n: size of heap
 * @i: index of root of subtree
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
	size_t max_val = i;
	size_t left_idx = 2 * i + 1;
	size_t right_idx = 2 * i + 2;

	if (left_idx < n && array[left_idx] > array[max_val])
		max_val = left_idx;

	if (right_idx < n && array[right_idx] > array[max_val])
		max_val = right_idx;

	if (max_val != i)
	{
		int temp = array[i];

		array[i] = array[max_val];
		array[max_val] = temp;
		print_array(array, size);
		heapify(array, size, n, max_val);
	}
}

/**
 * heap_sort - Sorts array of integers with Heap Sort algorithm
 *
 * @array: array to be sorted
 * @size: number of elements
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	for (size_t i = (size / 2) - 1; i-- > 0;)
		heapify(array, size, size, i);

	for (size_t i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
