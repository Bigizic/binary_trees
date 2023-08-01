#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree
 *
 * @parent: pointer to the node to be created
 *
 * @value: (int) value of node to be created
 *
 * Return: newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *current = NULL;

	if (parent == NULL && value == '\0')
		return (NULL);

	current = malloc(sizeof(binary_tree_t));

	if (current == NULL)
		return (NULL);

	current->parent = parent;
	current->left = NULL;
	current->right = NULL;
	current->n = value;

	return (current);
}
