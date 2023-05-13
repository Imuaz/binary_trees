#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: the measured height, 0 If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height, right_height; /*l = 0, r = 0;*/

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_height = tree->right ? 1 +  binary_tree_height(tree->right) : 0;

		if (left_height > right_height)
		{
			return (left_height);
		}
		return (right_height);
	}
	return (0);
}
