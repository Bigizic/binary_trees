#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node
 *
 * @node: pointer to the node to find the siblling
 *
 * Return: pointer to the sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *current = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	current = node->parent;

	if (current->left == node)
		return (current->right);

	if (current->right == node)
		return (current->left);

	return (NULL);
}
