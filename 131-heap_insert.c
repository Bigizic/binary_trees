#include "binary_trees.h"
#include <limits.h>

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
		else if (value < temp->left->n || value < temp->right->n)
		{
			if (temp->left->n > temp->right->n)
				temp = temp->left;
			else
				temp = temp->right;
		}
		else if (value > temp->right->n || value > temp->left->n)
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
