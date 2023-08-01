#include "binary_trees.h"

/**
 * binary_tree_inorder - a function that prints nodes data using
 * in-order travasal method
 *
 * @tree: pointer to binary tree to be printed
 *
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* use recursion to print nodes */
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
