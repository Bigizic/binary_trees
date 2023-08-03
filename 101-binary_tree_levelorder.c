#include "binary_trees.h"

void get_level(const binary_tree_t *tree, size_t i, void (*func)(int));
size_t get_height(const binary_tree_t *node);
/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 *
 * @tree: pointer to the root node
 *
 * @func: function that prints the tree value at each travsal
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, height;

	if (tree == NULL || func == NULL)
		return;
	height = get_height(tree);

	for (i = 1; i <= height; i++)
		get_level(tree, i, func);
}

/**
 * get_height - gets the height of a tree, works for this level-order only
 *
 * @node: pointer to the tree
 *
 * Return: height of tree
 */
size_t get_height(const binary_tree_t *node)
{
	size_t left, right;

	if (node == NULL)
		return (0);

	left = get_height(node->left);
	right = get_height(node->right);

	return (1 + (left >= right ? left : right));
}

/**
 * get_level - gets and prints the level of the tree
 *
 * @tree: pointer to the tree
 *
 * @i: level of the tree to print from
 *
 * @func: function to print
 *
 * Return: void
 */
void get_level(const binary_tree_t *tree, size_t i, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (i > 1)
	{
		get_level(tree->left, i - 1, func);
		get_level(tree->right, i - 1, func);
	}
	if (i == 1)
		func(tree->n);
}
