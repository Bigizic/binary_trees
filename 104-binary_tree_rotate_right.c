#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a
 * right-rotation on a binary tree
 *
 * @tree: tree to rotate
 *
 * Return: newly created tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *created_root = NULL;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	created_root = tree->left;
	tree->left = created_root->right;

	if (created_root->right != NULL)
		created_root->right->parent = tree;

	created_root->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->right == tree)
			tree->parent->right = created_root;
		else
			tree->parent->left = created_root;
	}

	created_root->right = tree;
	tree->parent = created_root;

	return (created_root);
}
