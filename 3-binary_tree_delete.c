#include "binary_trees.h"

/**
 * binary_tree_delete - a function that frees an enitre binary tree
 *
 * @tree: pointer to the tree to free
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* recursively delete tree left and right nodes */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);

}
