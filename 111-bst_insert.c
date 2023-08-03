#include "binary_trees.h"
#include <limits.h>

/**
 * bst_insert -  a function that inserts a value in a Binary Search Tree
 *
 * @tree: (double pointer) pointer to the root node of the BST
 *
 * @value: (int) value to be inserted
 *
 * Return: newly created node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new = *tree;

	while (new)
	{
		if (value == new->n)
			break;
		else if (value < new->n)
		{
			if (new->left == NULL)
			{
				new->left = binary_tree_node(new, value);
				return (new->left);
			}
			new = new->left;
		}
		else
		{
			if (new->right == NULL)
			{
				new->right = binary_tree_node(new, value);
				return (new->right);
			}
			new = new->right;
		}
	}
	return (NULL);
}
