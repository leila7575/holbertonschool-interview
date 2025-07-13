#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * find_max_element - gets the maximum value in array
 *@array: array to be searched in the max element
 *@size: number of elemnt in array
 * Return: the maximum value in array
 */
int find_max_element(int array[], int size)
{
	int max = array[0];

	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * digit_sort - sorts array of integers with LSD Radix sort algorithm
 *@array: array to be sorted
 *@size: number of elements in array
 *@digit_position: exponent
 */
void digit_sort(int array[], int size, int digit_position)
{
	int temp_array[size];
	int digit_count[10] = {0};

	for (int i = 0; i < size; i++)
	{
		int digit = (array[i] / digit_position) % 10;

		digit_count[digit]++;
	}

	for (int i = 1; i < 10; i++)
		digit_count[i] += digit_count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		int digit = (array[i] / digit_position) % 10;

		temp_array[digit_count[digit] - 1] = array[i];
		digit_count[digit]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = temp_array[i];
}

/**
 * radix_sort - sorts array of integers with LSD Radix sort algorithm
 *@array: array to be sorted
 *@size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int max = find_max_element(array, size);

	for (int digit_position = 1; max / digit_position > 0; digit_position *= 10)
	{
		digit_sort(array, size, digit_position);
		print_array(array, size);
	}
}
