#include "binary_trees.h"

/**
 * binary_tree_leaves -  counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: the counted leaves, 0If tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l_leaves, r_leaves;

	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL00)
		{
			return (1);
		}
		l_leaves = binary_tree_leaves(tree->left);
		r_leaves = binary_tree_leaves(tree->right);

		return (l_leaves + r_leaves);
	}
	return (0);
}
