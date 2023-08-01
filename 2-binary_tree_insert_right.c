#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node to the
 * right child of a given node
 *
 * @parent: pointer to the node to insert the right-child in
 *
 * @value: value of node to be inserted
 *
 * Return: newly inserted node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp_node = NULL;

	if (parent == NULL && value == '\0')
		return (NULL);

	if (parent == NULL)
		return (NULL);

	temp_node = malloc(sizeof(binary_tree_t));
	if (temp_node == NULL)
		return (NULL);

	temp_node->parent = parent;
	temp_node->left = NULL;
	temp_node->right = NULL;
	temp_node->n = value;

	if (parent->right != NULL)
	{
		temp_node->right = parent->right;
		parent->right->parent = temp_node;
	}
	parent->right = temp_node;
	return (temp_node);
}
