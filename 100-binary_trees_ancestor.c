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
	binary_tree_t *current = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	current = (binary_tree_t *)second;
	while (first)
	{
		while (current != NULL)
		{
			if (first == second)
			{
				return ((binary_tree_t *)current);
			}
			second = second->parent;
		}
		second = current;
		first = first->parent;
	}
	return (NULL);
}
