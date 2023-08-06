#include "binary_trees.h"

int two_child_case(avl_t *root);
int leaf_node_case(avl_t *root);


/**
 * avl_remove - a function that removes a node from an AVL tree
 *
 * @root: pointer to root of tree
 *
 * @value: value to be freed
 *
 * Return: node that it's value equals to value and it's freed
 */


avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = NULL;
	int tmp, bf;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (leaf_node_case(root) == 1)
		{
			free(root);
			return (NULL);
		}
		if (!root->left && root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->left;
			root->right->parent = root->parent;
			new_root = root->right;
			free(root);
			return (new_root);
		}
		else if (!root->right && root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
			new_root = root->left;
			free(root);
			return (new_root);
		}
		if (root->left && root->right)
		{
			tmp = two_child_case(root);
			root->n = tmp;
			root->right = avl_remove(root->right, root->n);
		}
	}

	bf = binary_tree_balance(root);
	if (bf == 2 && binary_tree_balance(root->left) >= 0)
		root = binary_tree_rotate_right(root);
	else if (bf == 2 && binary_tree_balance(root->left) == -1)
	{
		root->left = binary_tree_rotate_left(root->left);
		root = binary_tree_rotate_right(root);
	}
	else if (bf == -2 && binary_tree_balance(root->right) <= 0)
		root = binary_tree_rotate_left(root);
	else if (bf == -2 && binary_tree_balance(root->right) == 1)
	{
		root->right = binary_tree_rotate_right(root->right);
		root = binary_tree_rotate_left(root);
	}
	return (root);
}

/**
 * two_child_case - function that handles in case of a two child
 *
 * @root: pointer to root node
 *
 * Return: root value
 */
int two_child_case(avl_t *root)
{
	avl_t *tmp = NULL;

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
int leaf_node_case(avl_t *root)
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
