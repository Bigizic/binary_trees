#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_is_full - a function that checks if a binary tree is full\
 *
 * @tree: tree to check
 *
 * Return: 1 if tree is full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
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

	if (tree == NULL)
		return (0);

	right = binary_tree_height(tree->right);
	left = binary_tree_height(tree->left);

	return (1 + (left >= right ? left : right));
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

	if (binary_tree_is_full(tree))
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
 * binary_tree_is_complete - a function that checks if a binary tree
 * is complete
 *
 * @tree: tree to check
 *
 * Return: 1 if tree is complete otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree))
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
 * binary_tree_is_heap - a function that checks if a binary tree is a
 * valid Max Binary Heap
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if binary tree is complete 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int complete = 0, top = -1;
	binary_tree_t **temp = NULL, *curr = NULL;

	if (tree == NULL)
		return (0);

	complete = binary_tree_is_complete(tree);
	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
		return (0);

	temp[++top] = (binary_tree_t *)tree;
	while (top >= 0)
	{
		curr = temp[top--];
		if (curr->right)
		{
			if (curr->right->n > curr->n)
			{
				free(temp);
				return (0);
			}
			temp[++top] = curr->right;
		}
		if (curr->left)
		{
			if (curr->left->n > curr->n)
			{
				free(temp);
				return (0);
			}
			temp[++top] = curr->left;
		}
	}

	free(temp);
	if (complete == 1)
		return (1);

	return (0);
}
