#include "binary_trees.h"

/**
 * array_to_heap - a function that builds a Max Binary Heap tree from
 * an array
 *
 * @array: array containing elements used to build the binary tree
 *
 * @size: size of array
 *
 * Return: a pointer to the root node of the created Binary Heap,
 * otherwise or NULL
 */


heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *new = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		heap_insert(&new, array[i]);
	}
	return (new);
}
