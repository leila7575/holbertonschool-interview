#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

avl_t *build_tree_recursive(
	int *array, int start_index, int end_index, avl_t *parent_node
);

/**
 * sorted_array_to_avl -  converts array to binary tree
 * @array: pointer to first element of array to be converted
 * @size: number of elements in the array
 * Return: pointer to root node of AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (build_tree_recursive(array, 0, size - 1, NULL));
}

/**
 * build_tree_recursive - builds avl_tree using recursion
 *@array: pointer array to be converted
 *@start_index: pointer to start index of array
 *@end_index: pointer to end index of array
 *@parent_node: pointer to parent node
 * Return: newly created tree
 */
avl_t *build_tree_recursive(
	int *array, int start_index, int end_index, avl_t *parent_node
)
{
	int middle_index;
		avl_t *node;

	if (start_index > end_index)
		return (NULL);

	middle_index = (start_index + end_index) / 2;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->parent = parent_node;
	node->left = build_tree_recursive(array, start_index, middle_index - 1, node);
	node->right = build_tree_recursive(array, middle_index + 1, end_index, node);
	node->n = array[middle_index];

	return (node);
}
