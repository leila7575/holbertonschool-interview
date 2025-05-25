#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "binary_trees.h"

/**
 * swap - swaps values
 * @node1: pointer to first node.
 * @node2: pointer to second node.
 */
void swap(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_down - maintains Max Heap property
 * @node: start node for heapify down
 * Return: pointer to node after heapify down
 */
heap_t *heapify_down(heap_t *node)
{
	heap_t *max_node = node;

	while (
			(node->left && node->left->n > node->n) ||
			(node->right && node->right->n > node->n)
	      ){
		if (node->left && (!node->right || node->left->n > node->right->n))
		{
			max_node = node->left;
		}
		else if (node->right)
		{
			max_node = node->right;
		}
		swap(node, max_node);
		node = max_node;
	}
	return (node);
}

/**
 * heap_size - computes size of binary heap
 * @root: pointer to the root node of the heap
 * Return: heap size number of nodes of heap
 */
static size_t heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * last_node - gets last level-order node
 * @root: pointer to the root node of the heap
 * @size: size of heap
 * Return: pointer to last node
 */
static heap_t *last_node(heap_t *root, size_t size)
{
	if (!root || size == 0)
		return (NULL);

	if (size == 1)
		return (root);

	heap_t *current = root;
	size_t path = 1;

	while (path <= size)
	{
		path <<= 1;
	}
	path >>= 2;

	while (path > 0)
	{
		if (path & size)
		{
			current = current->right;
		}
		else
		{
			current = current->left;
		}
		path >>= 1;
	}

	return (current);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in root node, 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	heap_t *heap_root = *root;
	int root_value = heap_root->n;

	size_t size = heap_size(heap_root);

	if (size == 1)
	{
		free(heap_root);
		*root = NULL;
		return (root_value);
	}

	heap_t *last = last_node(heap_root, size);

	if (!last)
		return (0);

	heap_root->n = last->n;

	heap_t *parent = last->parent;

	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last);

	heapify_down(heap_root);

	return (root_value);
}
