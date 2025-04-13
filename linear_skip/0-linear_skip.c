#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - performs linear search for a value
 *in a sorted skip list of integers
 * @list: pointer to the head node of the skip list
 * @value: value to search
 * Return: pointer on node where value is located, NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *express;

	if (list == NULL)
		return (NULL);
	prev = list;
	express = list->express;
	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n >= value)
			break;
		prev = express;
		express = express->express;
	}
	if (express)
		printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, express->index);
	else
	{
		skiplist_t *tmp = prev;

		while (tmp->next)
			tmp = tmp->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, tmp->index);
	}
	while (prev)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		if (express && prev->index >= express->index)
			break;
		prev = prev->next;
	}
	return (NULL);
}
