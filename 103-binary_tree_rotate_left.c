#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a function that performs a left-rotation
 * on a binary tree
 *
 * @tree: tree to rotate
 *
 * Return: pointer to new tree that contain changes
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *created_root = NULL;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	created_root = tree->right;
	tree->right = created_root->left;

	if (created_root->left != NULL)
		created_root->left->parent = tree;

	created_root->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree == tree->parent->left)
			tree->parent->left = created_root;
		else
			tree->parent->right = created_root;
	}

	created_root->left = tree;
	tree->parent = created_root;

	return (created_root);
}
