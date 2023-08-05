#include "binary_trees.h"

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
	bst_t *new_root = NULL, *succp, *succ;

	if (root == NULL)
		return (NULL);

	if (root->n > value)
	{ root->left = bst_remove(root->left, value);
		return (root); }
	else if (root->n < value)
	{ root->right = bst_remove(root->right, value);
		return (root); }
	if (root->left == NULL)
	{
		new_root = root->right;
		free(root);
		return (new_root);
	}
	else if (root->right == NULL)
	{
		new_root = root->left;
		free(root);
		return (new_root);
	}
	else
	{
		succp = root;
		succ = root->right;
		while (succ->left != NULL)
		{
			succp = succ;
			succ = succ->left;
		}
		if (succp != root)
			succp->left = succ->right;
		else
			succp->right = succ->right;
		root->n = succ->n;
		free(succ);
		return (root);
	}
}
