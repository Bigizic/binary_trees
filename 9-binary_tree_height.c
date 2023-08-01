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
 * Description: height of a tree is the measured by the number of edges
 * from the leaf node to the tree
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
