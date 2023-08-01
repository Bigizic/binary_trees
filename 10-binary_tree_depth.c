#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_is_root - a function that checks if a node is a root
 *
 * @node: pointer to node to check
 *
 * Return: 1 if node is a root otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
	{
		return (1);
	}
	return (0);
}

/**
 * binary_tree_depth -  a function that measures the depth of a node
 * in a binary tree
 *
 * Description: node is measured by how many edges of the tree from the
 * root
 *
 * @tree: tree to be measured
 *
 * Return: depth of node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL || binary_tree_is_root(tree))
		return (0);

	while (tree->parent != NULL)
	{
		count++;
		tree = tree->parent;
	}
	return (count);
}
