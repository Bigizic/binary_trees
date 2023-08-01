#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary
 * tree
 *
 * @tree: tree to be measured
 *
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	right = binary_tree_height(tree->right);
	left = binary_tree_height(tree->left);

	return (1 + (left >= right ? left : right));
}


/**
 * binary_tree_is_perfect - a function that checks if a binary tree
 * is perfect
 * 
 * tree: pointer to tree to check
 *
 * Return: 1 if perfect otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return left == right;
}
