#include "binary_trees.h"

int is_complete_recursive(const binary_tree_t *tree, int index, int count);
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL or 1 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete_recursive - helper function to recursively check if
 * a binary tree is complete
 * @tree: pointer to the current node being checked
 * @index: current index of the node
 * @count: total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, count) &&
			is_complete_recursive(tree->right, 2 * index + 2, count));
}

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
