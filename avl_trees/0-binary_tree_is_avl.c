#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <limits.h>
#include <math.h>

/**
 * height - computes height of binary tree
 *@tree: pointer to the root node of tree to be checked
 * Return: height ogf the bianry tree
 */
int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (-1);

	left_h = height(tree->left);
	right_h = height(tree->right);

	if (left_h > right_h)
	{
		return (left_h + 1);
	}
	else
	{
		return (right_h + 1);
	}

}

/**
 * validate_BST - checks if binary tree is valid BST
 *@tree: pointer to the root node of tree to be checked
 *@max: max value bound
 * @min: min value bound
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int validate_BST(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	int left_BST = validate_BST(tree->left, min, tree->n);
	int right_BST = validate_BST(tree->right, tree->n, max);

	return (left_BST && right_BST);
}

/**
 * validate_AVL - checks AVL property
 *@tree: pointer to the root node of tree to be checked
 * Return: 1 if balanced binary tree, O otherwise
 */
int validate_AVL(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (1);

	left_h = height(tree->left);
	right_h = height(tree->right);

	if (abs(left_h - right_h) > 1)
		return (0);

	int left_AVL = validate_AVL(tree->left);
	int right_AVL = validate_AVL(tree->right);

	return (left_AVL && right_AVL);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *@tree: pointer to the root node of tree to be checked
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!validate_BST(tree, INT_MIN, INT_MAX))
		return (0);

	if (!validate_AVL(tree))
		return (0);

	return (1);
}
