#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps the values of two nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_up - Maintains the Max Heap property after insertion.
 * @node: The newly inserted node.
 * 
 * Return: Pointer to the node after heapify-up (new position).
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
    return node;
}

/**
 * count_nodes - Counts the number of nodes in the binary tree.
 * @node: Pointer to the root node.
 * 
 * Return: Number of nodes in the tree.
 */
int count_nodes(heap_t *node)
{
    if (!node)
        return 0;
    return 1 + count_nodes(node->left) + count_nodes(node->right);
}

/**
 * insert_at_position - Inserts a new node at the correct position in level-order.
 * @node: Pointer to the current node.
 * @value: Value to insert into the new node.
 * @position: Position of the new node in level-order traversal.
 * @current: Current position of the node being visited.
 * 
 * Return: Pointer to the newly inserted node, or NULL on failure.
 */
heap_t *insert_at_position(heap_t *node, int value, int position, int current)
{
    if (!node)
        return NULL;

    if (current == position)
        return binary_tree_node(node, value);

    heap_t *left_result = NULL;

    if (node->left)
        left_result = insert_at_position(node->left, value, position, current * 2);

    if (left_result)
        return left_result;

    if (node->right)
        return insert_at_position(node->right, value, position, current * 2 + 1);

    return NULL;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to insert into the heap.
 * 
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (!root)
        return NULL;

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return *root;
    }

    int total_nodes = count_nodes(*root);
    int position = total_nodes + 1;

    new_node = insert_at_position(*root, value, position, 1);

    if (!new_node)
        return NULL;

    return heapify_up(new_node);
}
