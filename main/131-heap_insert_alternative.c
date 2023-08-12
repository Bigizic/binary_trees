#include "binary_trees.h"
#include <stdbool.h>

int l_c(heap_t *node)
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

int r_c(heap_t *node)
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

heap_t *swapper(heap_t *node)
{
	int temp;
	heap_t *swapped;

	if (node == NULL)
		return (NULL);

	swapped = node;
	if (swapped->parent != NULL && swapped->n > swapped->parent->n)
	{
		temp = swapped->n;
		swapped->n = swapped->parent->n;
		swapped->parent->n = temp;
		swapped = swapped->parent;
	}
	return (swapped);
}


heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *temp, *new;
	int temp_value, lc, rc, lrc, rrc;

	if (root == NULL)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (*root == NULL)
	{
		*root = new;
		return (new);
	}

	temp = *root;
	while (temp->left != NULL && temp->right != NULL)
	{
		lc = l_c(temp->left);
		lrc = r_c(temp->left);
		rc = l_c(temp->right);
		rrc = r_c(temp->right);
		if (value < temp->n)
		{
			if ((lc == 0 || lc > 0) && lrc == 0)
			{
				temp = temp->left;
				lc = l_c(temp);
				lrc = r_c(temp);
				if (lc == 0 && lrc == 0)
				{
					if (value < temp->n && value)
					{
						temp->left = binary_tree_node(temp, value);
						return (temp->left);
					}
				else if (value > temp->n && value)
					return (swapper(temp->left));
				}
				else if (lc > 1 && lrc == 0)
				{
					if (value < temp->n)
						temp->right = binary_tree_node(temp, value);
					else
						temp->left = binary_tree_node(temp, value);
				}
			}
			if (lc > 0 && lrc > 0)
			{
				temp = temp->right;
				rc = l_c(temp);
				rrc = r_c(temp);
				if (rc == 0 && rrc == 0)
				{
					if (value > temp->n)
					{
						temp->left = binary_tree_node(temp, value);
						return (swapper(temp->left));
					}
					else
					{
						temp = binary_tree_node(temp, value);
						return (temp->left);
					}
				}
				if (rc > 0 && rrc == 0)
				{
					if (value > temp->n)
					{
						temp->right = binary_tree_node(temp, value);
						swapper(temp->right);
					}
				}
			}
		}
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
