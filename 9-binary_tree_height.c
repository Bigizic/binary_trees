#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary
 * tree
 *
 * Description: height of a tree is the measured by the number of nodes
 * from the leaf node to the tree, depth is measured by nummber of edges
 * from the leaf to the tree. Normally we'd add 1 to the depth to get the
 * height
 *
 * @tree: tree to be measured
 *
 * Return: height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}
