#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from
 * an array, using bst_insert to insert the array and value
 *
 * @array: array to build tree from
 *
 * @size: size of array
 *
 * Return: a pointer to newly created tree
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *new = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&new, array[i]);
	}
	return (new);
}
