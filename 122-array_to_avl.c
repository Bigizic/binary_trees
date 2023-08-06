#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL tree from an array
 *
 * @array: array to build tree from
 *
 * @size: size of array
 *
 * Return: pointer to newly created tree
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *new = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&new, array[i]);
	return (new);
}
