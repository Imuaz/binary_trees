#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return:  the measured depth, 0 f tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t depth = 0;
		const binary_tree_t *current = tree;

		while (current->parent)
		{
			depth++;
			current = current->parent;
		}
		return (depth);
	}
	return (0);
}
