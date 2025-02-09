#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome_recursive - recursive function to ckeck palindrome.
 *@last: Pointer to the end of the list.
 *@first: Pointer to the start of the list.
 * Return: 1 if palindrome.
 */
int is_palindrome_recursive(listint_t *last, listint_t **first)
{
	if (last == NULL)
		return (1);

	int check_palindrome = is_palindrome_recursive(last->next, first);

	if (!check_palindrome)
		return (0);

	if ((*first)->n != last->n)
		return (0);

	*first = (*first)->next;

	return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the linked list.
 *
 * Return: 1 if the linked list is a palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	return (is_palindrome_recursive(*head, head));
}
