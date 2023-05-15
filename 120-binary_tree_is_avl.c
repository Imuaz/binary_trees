#include<limits.h>
#include "binary_trees.h"

int avl_helper(const binary_tree_t *tree, int low, int high);
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
/**
 * avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t l_hght, r_hght, height;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		l_hght = binary_tree_height(tree->left);
		r_hght = binary_tree_height(tree->right);
		height = l_hght > r_hght ? l_hght - r_hght : r_hght - l_hght;
		if (height > 1)
			return (0);
		return (avl_helper(tree->left, low, tree->n - 1) &&
				avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (avl_helper(tree, INT_MIN, INT_MAX));
}
