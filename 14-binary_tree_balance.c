#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 *
 * @node: node to check if it's a leaf
 *
 * Return: 1 if it's a leaf otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

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

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	right = binary_tree_height(tree->right);
	left = binary_tree_height(tree->left);

	return (1 + (left >= right ? left : right));
}

/**
 * a function that measures the balance factor of a binary tree
 *
 * @tree: tree to be measured
 *
 * Return: measurement of balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL))
		return (-1);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return ((int)(left - right));

}
