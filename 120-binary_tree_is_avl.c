#include<limits.h>
#include "binary_trees.h"

int bt_is_avl_helper(const binary_tree_t *tree, int lo,
		int hi, size_t *height);
/**
 * bt_is_avl_helper- Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 * @height: height of the tree
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int bt_is_avl_helper(const binary_tree_t *tree, int lo, int hi, size_t *height)
{
	int is_left_avl, is_right_avl;
	size_t left_height, right_height;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}
	if (tree->n < lo || tree->n > hi)
		return (0);
	is_left_avl = bt_is_avl_helper(tree->left, lo, tree->n - 1, &left_height);
	is_right_avl = bt_is_avl_helper(tree->right, tree->n + 1, hi, &right_height);

	*height = 1 + (left_height > right_height ? left_height : right_height);

	if (abs((int)left_height - (int)right_height) > 1)
		return (0);

	return (is_left_avl && is_right_avl);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);

	return (bt_is_avl_helper(tree, INT_MIN, INT_MAX, &height));
}
