#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	binary_tree_t *new_root = tree->right;
	binary_tree_t *subtree = new_root->left;
	/*Perform the rotation*/
	new_root->left = tree;
	tree->right = subtree;
	/*Update parent pointers*/
	if (subtree != NULL)
		subtree->parent = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
