#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *subtree;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	subtree = new_root->left;
	new_root->left = tree;
	tree->right = subtree;
	if (subtree != NULL)
		subtree->parent = tree;
	subtree = tree->parent;
	tree->parent = new_root;
	new_root->parent = subtree;
	if (subtree != NULL)
	{
		if (subtree->left == tree)
			subtree->left = new_root;
		else
			subtree->right = new_root;
	}

	return (new_root);
}
