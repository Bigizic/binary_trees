#include "binary_trees.h"

int is_complete(binary_tree_t *tree);
/**
 * binary_tree_is_heap -  a function that checks if a binary tree
 * is a valid Max Binary Heap
 *
 * @tree: tree to be checked
 *
 * Return: 1 if tree is valid MAX binary heap otherwise 0
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int count = 0;
	binary_tree_t *root;

	if (tree == NULL)
		return (0);

	root = (binary_tree_t *)tree;

	while (root)
	{
		count++;
		root = root->left;
	}
	return ();
}


/**
 * is_complete - checks if a tree is complete
 *
 * @tree: tree to check
 *
 * Return: 0 or 1
 */

int is_complete(binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_full == 1)
		return (1);

	left = binary_tree_height(tree->left);
	right =  binary_tree_height(tree->right);

	if (left == right)
	{
		if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_complete(tree->right))
			return (1);
	}
	else if (left == right + 1)
	{
		if (binary_tree_is_complete(tree->left) &&
				binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
}


/**
 * binary_tree_is_perfect - a function that checks if a binary tree
 * is perfect
 *
 * @tree: pointer to tree to check
 *
 * Return: 1 if perfect otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (binary_tree_is_full == 1)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right))
			return (1);
	}
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


	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		binary_tree_is_full = 1;

	right = binary_tree_height(tree->right);
	left = binary_tree_height(tree->left);

	return (1 + (left >= right ? left : right));
}
