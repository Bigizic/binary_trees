#include "binary_trees.h"
#include <limits.h>

/**
 * b_height - height checker
 *
 * @node: node
 *
 * Return: height of node
 */
size_t b_height(binary_tree_t *node)
{
	size_t left = 0, right = 0;

	if (node == NULL)
		return (0);

	if (node != NULL)
	{
		if (node->left)
			left = 1 + b_height(node->left);
		else
			left = 1;

		if (node->right)
			right = 1 + b_height(node->right);
		else
			right = 1;

		return ((left > right) ? left : right);
	}
	return (0);
}

/**
 * b_t_is_avl_helper - a function that checks if a binary tree
 * is a valid AVL Tree
 *
 * @tree: pointer to tree to check
 *
 * @min: minimum
 *
 * @max: maximum
 *
 * Return: 1 if tree is valid AVL otherwise 0
 */

int b_t_is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	size_t clear;
	size_t left_avl, right_avl;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
		{
			return (0);
		}
		left_avl = b_height(tree->left);
		right_avl = b_height(tree->right);

		if (left_avl > right_avl)
			clear = left_avl - right_avl;
		clear = right_avl - left_avl;

		if (clear > 1)
			return (0);
		return (b_t_is_avl_helper(tree->left, min, tree->n - 1) &&
				b_t_is_avl_helper(tree->right, tree->n + 1, max));
	}
	return (1);
}


/**
 * binary_tree_is_avl - a function that checks if a binary tree is a
 * valid AVL tree
 *
 * @tree: pointer to tree to check
 *
 * Return: 1 if tree is valid AVL otherwise 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (b_t_is_avl_helper(tree, INT_MIN, INT_MAX));
}
