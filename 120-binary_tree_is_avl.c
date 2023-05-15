#include<limits.h>
#include "binary_trees.h"

int avl_helper(const binary_tree_t *tree, int min_val, int max_val, size_t *h);
/**
 * avl_helper - checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min_val: The minimum value constraint for the nodes in the subtree.
 * @max_val: The maximum value constraint for the nodes in the subtree.
 * @h: A pointer to a variable to store the height of the subtree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int avl_helper(const binary_tree_t *tree, int min_val, int max_val, size_t *h)
{
	size_t left_height, right_height;
	int is_left_avl, is_right_avl;

	if (tree == NULL)
	{
		*h = 0;
		return (1);
	}
	if (tree->n <= min_val || tree->n >= max_val)
		return (0);

	is_left_avl = avl_helper(tree->left, min_val, tree->n, &left_height);
	is_right_avl = avl_helper(tree->right, tree->n, max_val, &right_height);

	*h = 1 + (left_height > right_height ? left_height : right_height);

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

return (avl_helper(tree, INT_MIN, INT_MAX, &height));
}
