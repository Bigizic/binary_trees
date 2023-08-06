#include "binary_trees.h"

avl_t *avl_helper(avl_t **tree, avl_t *root, avl_t **node, int value);

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
 */
avl_t *avl_helper(avl_t **tree, avl_t *root, avl_t **node, int value)
{
	int bal;

	if (*tree == NULL)
		return (*node = binary_tree_node(root, value));

	if (value < (*tree)->n)
		(*tree)->left = avl_helper(&(*tree)->left, *tree, node, value);
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_helper(&(*tree)->right, *tree, node, value);
	}
	else
		return (*tree);

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
		*tree = binary_tree_rotate_right(*tree);
	}
	return (*tree);
}
