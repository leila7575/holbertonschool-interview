#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - creates a new node
 *
 * @val:string to copy in the node
 * Return: new node
 */
List *create_node(char *val)
{
	List *node = malloc(sizeof(List));

	node->str = strdup(val);
	node->next = node;
	node->prev = node;
	return (node);

}


/**
 * add_node_end - inserts new node at the end of double circular linked list
 *
 * @list: list to modify
 * @str: string to copy to new node
 *
 * Return:  Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node = create_node(str);

	if (*list == NULL)
	{
		*list = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
	return (node);
}


/**
 * add_node_begin - inserts new node at the beginning of circular linked list
 *
 * @list: list to modify
 * @str: string to copy to new node
 *
 * Return:  Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node = create_node(str);

	if (*list == NULL)
	{
		*list = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
		*list = node;
	}
	return (node);
}
