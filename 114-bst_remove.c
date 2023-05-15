#include "binary_trees.h"

bst_t *find_successor(bst_t *node);
/**
 * find_successor - finds the in-order successor of a node in a BST
 * @node: pointer to the node
 *
 * Return: pointer to the in-order successor node
 */
bst_t *find_successor(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;
	return (current);
}
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
	bst_t *temp, *successor;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		successor = find_successor(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
