#include "binary_trees.h"
#include <limits.h>

/**
 * bst_helper - a function that measures the size of a binary tree
 *
 * @tree: tree to be measured
 *
 * @p: minimum value that can be be stored in an int data
 *
 * Return: the size of the tree
 */
int bst_helper(const binary_tree_t *tree, int *p)
{
	if (tree == NULL)
		return (1);

	if (!bst_helper(tree->left, p))
		return (0);

	if (*p >= tree->n)
		return (0);

	*p = tree->n;

	return (bst_helper(tree->right, p));
}


/**
 * binary_tree_is_bst - a function that checks if a binary tree is a
 * valid Binary Search Tree
 *
 * @tree: tree to check if it's a valid BST
 *
 * Return: 1 if it's a valid BST otherwise 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int p;

	if (tree == NULL)
		return (0);

	p = INT_MIN;

	return (bst_helper(tree, &p));
}
