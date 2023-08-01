#include "binary_trees.h"

/**
 * a function that finds the uncle of a node
 *
 * Description: uncle node is basically the left or right node of the
 * parent, just like brother of the parent
 *
 * node: pointer to node to find it's uncle
 *
 * Return: pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *current = NULL, *grand_parents = NULL;

	if (node == NULL)
		return (NULL);

	current = node->parent;
	grand_parents = current->parent;
	if (grand_parents == NULL)
		return (NULL);

	if (grand_parents->left->left == node)
		return (grand_parents->right);
	if (grand_parents->left->right == node)
		return (grand_parents->right);


	if (grand_parents->right->left == node)
		return (grand_parents->left);
	if (grand_parents->right->right == node)
		return (grand_parents->left);

	return (NULL);
}
