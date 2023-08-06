#include "binary_trees.h"

avl_t *avl_helper(avl_t **tree, avl_t *root, avl_t **node, int value);
int binary_treee_balance(const binary_tree_t *tree);
size_t bt_height(const binary_tree_t *tree);

/**
 * avl_insert -  a function that inserts a value in an AVL Tree
 *
 * @tree: double pointer to the tree where the value would be inserted
 *
 * @value: value to be inserted
 *
 * Return: newly created tree
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_helper(tree, *tree, &node, value);
	return (node);
}


/**
 * avl_helper - helper function for the recursion on avl insertion
 *
 * @tree: double pointer to original tree i.e the root tree to insert
 * into
 *
 * @root: pointer to the tree parent
 *
 * @node: double pointer to store the newly created node
 *
 * @value: value to be inserted
 *
 * Return: pointer to the new root after changes have been made
 * otherwise return NULL
 */
avl_t *avl_helper(avl_t **tree, avl_t *root, avl_t **node, int value)
{
	int bal;

	if (*tree == NULL)
		return (*node = binary_tree_node(root, value));

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_helper(&(*tree)->left, *tree, node, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_helper(&(*tree)->right, *tree, node, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);
	/*if ((*tree)->right != NULL && (*tree)->left == NULL)*/
		/*bal = binary_treee_balance(*tree);*/
	/*else*/
	bal = binary_tree_balance(*tree);

	if (bal > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	if (bal < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);

	if (bal > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	if (bal < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}


/**
 * binary_treee_balance - works for avl tree insertion
 *
 * @tree: pointer to tree to measure balance
 *
 * Return: (int) balanced value
 */
int binary_treee_balance(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (bt_height(tree->left) - bt_height(tree->right));
	return (0);
}


/**
 * bt_height - measures height of avl tree
 *
 * @tree: pointer to tree to be measured
 *
 * Return: (int) height of tree
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree != NULL && tree->left != NULL)
		left = 1 + binary_tree_height(tree->left);
	else
		left = 1;

	if (tree != NULL && tree->right != NULL)
		right = 1 + binary_tree_height(tree->right);
	else
		right = 1;
	return ((left > right) ? left : right);
}
