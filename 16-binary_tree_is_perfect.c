#include "binary_trees.h"

/**
 * perfect_height - gets height of a tree and checks for fullness
 * @tree: tree to check
 *
 * Return: height of the tree if perfect, 0 otherwise
 */
size_t perfect_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = perfect_height(tree->left);
	right_height = perfect_height(tree->right);

	if (left_height == right_height)
		return (left_height + 1);

	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left == NULL) != (tree->right == NULL))
		return (0);

	h_left = perfect_height(tree->left);
	if (h_left == 0)
		return (0);

	h_right = perfect_height(tree->right);
	if (h_right != h_left)
		return (0);

	return (1);
}
