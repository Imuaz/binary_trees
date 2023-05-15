#include "binary_trees.h"

bst_t *bst_delete(bst_t *root, bst_t *node);
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root:  a pointer to the root node of the tree where the a node is removed
 * @value: the value to remove from the tree
 *
 * Return: a pointer to the new root node of the tree after removing
 * the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root;

	while (node != NULL)
	{
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (bst_delete(root, node));
	}
	return (root);
}
/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent, *child, *successor;

	parent = node->parent;
	child = NULL;

	if (node->left == NULL)
		child = node->right;
	else if (node->right == NULL)
		child = node->left;
	else
	{
		successor = node->right;

		while (successor->left != NULL)
			successor = successor->left;

		if (successor->parent != node)
		{
			successor->parent->left = successor->right;
			if (successor->right != NULL)
				successor->right->parent = successor->parent;

			successor->right = node->right;
			node->right->parent = successor;
		}
		successor->left = node->left;
		node->left->parent = successor;
		child = successor;
	}
	if (child != NULL)
		child->parent = parent;
	if (parent != NULL)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		root = child;
	free(node);

	return (root);
}
