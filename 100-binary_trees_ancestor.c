#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the lowest common
 * ancestor of two nodes
 *
 * @first: pointer to first node
 *
 * @second: pointer to second node
 *
 * Return: lowest commmon ancestor of both nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t **first_ones = (binary_tree_t **)malloc(
			sizeof(binary_tree_t *) * 1024);
	const binary_tree_t *current = NULL;
	int num_first_ones = 0, i;

	if (first == NULL || second == NULL)
		return (NULL);

	current = first;
	while (current != NULL)
	{
		first_ones[num_first_ones++] = (binary_tree_t *)current;
		current = current->parent;
	}
	current = second;
	while (current != NULL)
	{
		for (i = 0; i < num_first_ones; i++)
		{
			if (current == first_ones[i])
			{
				free(first_ones);
				return ((binary_tree_t *)current);
			}
		}
		current = current->parent;
	}
	free (first_ones);
	return (NULL);
}
