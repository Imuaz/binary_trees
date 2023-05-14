#include "binary_trees.h"
#include <limits.h>

int check_bst(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}

/**
 * check_bst - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value constraint for the nodes in the subtree
 * @max: Maximum value constraint for the nodes in the subtree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (check_bst(tree->left, min, tree->n) &&
			check_bst(tree->right, tree->n, max));
}
