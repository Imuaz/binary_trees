#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the Balance factor, 0 If tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

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

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_height = tree->right ? 1 +  binary_tree_height(tree->right) : 1;

		if (left_height > right_height)
		{
			return (left_height);
		}
		return (right_height);
	}
	return (0);
}
