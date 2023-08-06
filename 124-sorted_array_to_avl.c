#include "binary_trees.h"

avl_t *merge_algo(int *array, int left_start, int right_end, avl_t *root);

/**
 * sorted_array_to_avl -  a function that builds an AVL tree from
 * a sorted array
 *
 * @array: sorted array to build tree from
 *
 * @size: size of sorted array
 *
 * Return: a pointer to the root node of the created AVL tree else NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (merge_algo(array, 0, size - 1, NULL));
}

/**
 * merge_algo - a function that use recursion to sort the nodes of an
 * AVL tree from a sorted array
 *
 * @array: pointer to array containing elements
 *
 * @left_start: start of the left index
 *
 * @right_end: end of the right index
 *
 * @root: pointer to the parent node which is NULL
 *
 * Return: newly created node and it's values
 */

avl_t *merge_algo(int *array, int left_start, int right_end, avl_t *root)
{
	int middle;
	avl_t *tree;

	if (left_start > right_end)
		return (NULL);

	middle = (left_start + right_end) / 2;

	tree = calloc(1, sizeof(avl_t));
	if (tree == NULL)
		return (NULL);

	tree->parent = root;
	tree->left = merge_algo(array, left_start, middle - 1, tree);
	tree->right = merge_algo(array, middle + 1, right_end, tree);
	tree->n = array[middle];

	return (tree);
}
