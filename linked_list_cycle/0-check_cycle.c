#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if singly linked list has cycle.
 *@list: pointer te head of the singly linked list to be checked
 * Return: 1 if there is a cycle, 0 otherwise.
 */
int check_cycle(listint_t *list)
{
	listint_t *first_pointer = list;
	listint_t *second_pointer = list;

	while (first_pointer && second_pointer && second_pointer->next)
	{
		first_pointer = first_pointer->next;
		second_pointer = second_pointer->next->next;

		if (first_pointer == second_pointer)
			return (1);
	}
	return (0);
}
