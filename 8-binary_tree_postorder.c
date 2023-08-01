#include "binary_trees.h"

/**
 * binary_tree_postorder - a function that prints nodes data using
 * post-order travasal method
 *
 * @tree: pointer to binary tree to be printed
 *
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
