#include "binary_trees.h"

int two_child_case(bst_t *root);
int leaf_node_case(bst_t *root);

/**
 * bst_remove -  a function that removes a node from a Binary Search Tree
 * given the value
 *
 * @root: pointer to root of the tree
 *
 * @value: value to be removed
 *
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_root = NULL;
	int tmp;

	if (root == NULL)
		return (root);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (leaf_node_case(root) == 1)
		{
			free(root);
			return (NULL); }
		if (!root->left && root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->left;
			root->right->parent = root->parent;
			new_root = root->right;
			free(root);
			return (new_root); }
		else if (!root->right && root->left)
		{
			if (root->parent->right == root)
			root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
			new_root = root->left;
			free(root);
			return (new_root); }
		if (root->left && root->right)
		{
			tmp = two_child_case(root);
			root->n = tmp;
			root->right = bst_remove(root->right, root->n); }
	}
	return (root);
}

/**
 * two_child_case - function that handles in case of a two child
 *
 * @root: pointer to node
 *
 * Return: root value
 */
int two_child_case(bst_t *root)
{
	bst_t *tmp = NULL;

	tmp = root->right;

	while (tmp->left)
		tmp = tmp->left;
	return (tmp->n);
}

/**
 * leaf_node_case - function that handles in case of a leaf node
 *
 * @root: pointer to root
 *
 * Return: 1 if success otherwise 0
 */
int leaf_node_case(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		return (1);
	}
	return (0);
}
