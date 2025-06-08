#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop -  finds the loop in a linked list
 * @head: pointer to head
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first_pointer = head, *second_pointer = head;

	while (first_pointer && second_pointer && second_pointer->next)
	{
		first_pointer = first_pointer->next;
		second_pointer = second_pointer->next->next;

		if (first_pointer == second_pointer)
		{
			first_pointer = head;
			while (first_pointer != second_pointer)
			{
				first_pointer = first_pointer->next;
				second_pointer = second_pointer->next;
			}
			return (first_pointer);
		}
	}
	return (NULL);
}
