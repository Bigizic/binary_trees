#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a Binary
 * Search Tree
 *
 * @tree: tree to search from
 *
 * @value: value to look for
 *
 * Return: pointer to the node that contain value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *radar = NULL;

	if (tree == NULL)
		return (NULL);

	radar = (bst_t *)tree;

	while (radar->n != value)
	{
		if (radar != NULL)
		{
			/* go to left tree else go to right */
			if (radar->n > value)
				radar = radar->left;
			else
				radar = radar->right;

			if (radar == NULL)
				return (NULL);
		}
	}
	return (radar);
}
