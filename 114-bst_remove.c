#include "binary_trees.h"

/**
 * inorder_successor - checks if the node has two children, find the
 * inorder successor
 *
 * @node: node to search
 *
 * Return: new node
 */
bst_t *inorder_successor(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node && node->left != NULL)
		node = node->left;

	return (node);
}

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
	bst_t *new_root = NULL, *successor;

	if (root == NULL)
		return (NULL);

	if (value <= root->n)
		root->left = bst_remove(root->left, value);
	else if (value >= root->n)
		root->right = bst_remove(root->right, value);
	else
	{
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
		successor = inorder_successor(root->right);
		root->n = successor->n;

		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
