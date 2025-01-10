#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: number to be included into the sorted linked list
 * Return: address of the new node or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new;
listint_t *current;

new = malloc(sizeof(listint_t));

if (new == NULL)
{
return (NULL);
}

new->n = number;
new->next = NULL;

if (*head == NULL || (*head)->n >= new->n)
{
*head = new;
}
else
{
current = *head;
while (current->next != NULL && current->next->n < new->n)
{
current = current->next;
}
new->next = current->next;
current->next = new;
}
return (new);
}
