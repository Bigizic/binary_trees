#include "binary_trees.h"
#include <limits.h>

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

	while (temp->left != NULL && temp->right != NULL)
	{
		if (value == temp->n)
			break;
		else if (value < temp->left->n)
		{
			if (temp->left->n > temp->right->n &&
					(left_check(temp->left) == 0 &&
					 right_check(temp->left) == 0))
				temp = temp->left;
			else if (temp->left->n < temp->right->n)
			{
				if (left_check(temp->left) != 0 &&
						right_check(temp->left) != 0)
				{
					if (left_check(temp->right) != 0 &&
							right_check(temp->right) != 0)
					{
						temp = temp->left->left;
					}
				}
			}
			else
				temp = temp->right;
		}
		else if (value > temp->left->n)
		{
			if (temp->left->n > temp->right->n &&
					(left_check(temp->left) != 0 &&
					 right_check(temp->left) == 0))
				temp = temp->left;
			else
				temp = temp->right;
		}
		else if (value > temp->right->n)
		{
			if (temp->left->n < temp->right->n)
				temp = temp->right;
			else
				temp = temp->left;
		}
		else
			break;
	}
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
