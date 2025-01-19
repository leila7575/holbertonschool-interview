#include "binary_trees.h"

/**
 * swap - swpas values
 * @node1: first node.
 * @node2: second node.
 */
void swap(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify - Max Heap property
 * @node: inserted node.
 *
 * Return: pointer to inserted node..
 */
heap_t *heapify(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * insert - inserts node using recursion
 * @root: pointer to root node.
 * @value: value to be inserted.
 *
 * Return: pointer to inserted node.
 */
heap_t *insert(heap_t *root, int value)
{
	if (!root)
		return (binary_tree_node(NULL, value));

	if (!root->left)
	{
		root->left = binary_tree_node(root, value);
		return (root->left);
	}
	else if (!root->right)
	{
		root->right = binary_tree_node(root, value);
		return (root->right);
	}
	else
	{
		heap_t *left_insert = insert(root->left, value);

		if (left_insert)
			return (left_insert);
		return (insert(root->right, value));
	}
}

/**
 * heap_insert - inserts value.
 * @root: double pointer to root node.
 * @value: value to be inserted
 * Return: pointer to inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new_node = insert(*root, value);

	if (!new_node)
		return (NULL);

	return (heapify(new_node));
}
