#include "binary_trees.h"

/**
 * heap_extract - extracts the root node from a max heap
 *
 * @root: double pointer to the root node
 *
 * Return: value of the extracted node, or INT_MIN if root is NULL
 */
int heap_extract(heap_t **root)
{
	int temp, extracted_value;
	heap_t *node;

	if (root == NULL || *root == NULL)
		return (0);

	extracted_value = (*root)->n;
	node = *root;

	while (node->left != NULL || node->right != NULL)
	{
		if (node->right == NULL || node->left->n >= node->right->n)
			node = node->left;
		else
			node = node->right;
	}

	(*root)->n = node->n;

	if (node->parent != NULL)
	{
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}

	free(node);

	node = *root;

	while ((node->left != NULL && node->n < node->left->n) ||
			(node->right != NULL && node->n < node->right->n))
	{
		if (node->right == NULL || node->left->n >= node->right->n)
		{
			temp = node->n;
			node->n = node->left->n;
			node->left->n = temp;
			node = node->left;
		}
		else
		{
			temp = node->n;
			node->n = node->right->n;
			node->right->n = temp;
			node = node->right;
		}
	}

	return (extracted_value);
}
