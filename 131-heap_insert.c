#include "binary_trees.h"
#include <limits.h>

heap_t *heap_helper(heap_t *temp, int value);

/**
 * left_check - a function that checks left node of a node and returns the
 * number of nodes in the left node
 *
 * @node: pointer to node to perform left check operation
 *
 * Return: 0 if node is NULL otherwise return number of left nodes
 */
int left_check(const heap_t *node)
{
	int count = 0;

	if (node == NULL)
		return (0);
	while (node->left != NULL)
	{
		count++;
		node = node->left;
	}
	return (count);
}


/**
 * right_check - a function that checks right node and return the number
 * of nodes in the right node
 *
 * @node: pointer to node to perform right check operation
 *
 * Return: 0 if node is NULL otherwise return number of right nodes
 */
int right_check(const heap_t *node)
{
	int count = 0;

	if (node == NULL)
		return (0);
	while (node->right != NULL)
	{
		count++;
		node = node->right;
	}
	return (count);
}


/**
 * heap_insert -  a function that inserts a value in a Binary Heap Tree
 *
 * @tree: (double pointer) pointer to the root node
 *
 * @value: (int) value to be inserted
 *
 * Return: newly created node
 */

heap_t *heap_insert(heap_t **tree, int value)
{
	heap_t *new, *temp;
	int temp_value;

	if (tree == NULL)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	}

	temp = *tree;
	temp = heap_helper(temp, value);

	if (temp->left == NULL)
		temp->left = new;
	else
		temp->right = new;

	new->parent = temp;

	while (new->parent && new->n > new->parent->n)
	{
		temp_value = new->n;
		new->n = new->parent->n;
		new->parent->n = temp_value;
		new = new->parent;
	}
	return (new);
}


/**
 * heap_helper - helper function for heap insert
 *
 * @temp: pointer to temp node
 *
 * @value: value of node to insert
 *
 * Return: altered node
 */
heap_t *heap_helper(heap_t *temp, int value)
{
	if (value == temp->n)
		return (temp);
	while (temp->left != NULL && temp->right != NULL)
	{
		if (value < temp->left->n)
		{
			if (temp->left->n > temp->right->n &&
					(left_check(temp->left) == 0 &&
					 right_check(temp->left) == 0))
			{
				return (temp->left);
			}
			else if (temp->left->n < temp->right->n)
			{
				if (left_check(temp->left) != 0 &&
						right_check(temp->left) != 0)
				{
					if (left_check(temp->right) != 0 &&
							right_check(temp->right) != 0)
						return (temp->left->left);
				}
			}
			else
				return (temp->right);
		}
		else if (value > temp->left->n)
		{
			if (temp->left->n > temp->right->n &&
					(left_check(temp->left) != 0 &&
					 right_check(temp->left) == 0))
				return (temp->left);
			else
				return (temp->right);
		}
		else if (value > temp->right->n)
		{
			if (temp->left->n < temp->right->n)
				return (temp->right);
			else
				return (temp->left);
		}
		else
			break;
	}
	return (temp);
}
