#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: the measured size, 0 If tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l_size, r_size;

		l_size = binary_tree_size(tree->left);
		r_size = binary_tree_size(tree->right);

		return (1 + l_size + r_size);
	}
	return (0);
}

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
		size_t left_height, right_height;

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to checks
 *
 * Return: 1, 0 If tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, node_count, max_nodes;

	if (tree == NULL)
	{
		return (0);
	}
	height = binary_tree_height(tree);
	node_count = binary_tree_size(tree);

	max_nodes = (1 << height) - 1;

	return (node_count == max_nodes);
}
