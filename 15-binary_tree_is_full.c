#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 *
 * @tree: tree to check
 *
 * Return: 1 if tree is full otherwise 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return (left && right);
	}
	return (0);
}
