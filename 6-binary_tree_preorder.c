#include "binary_trees.h"

/**
 * binary_tree_preorder - a function that prints nodes data using
 * pre-order travasal method
 *
 * @tree: pointer to binary tree to be printed
 *
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* use recursion to print nodes */
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
