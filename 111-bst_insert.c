#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	bst_t *curr = *tree;
	bst_t *parent = NULL;

	while (curr != NULL)
	{
		parent = curr;

		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else
			return (NULL); /* Value already exists, ignore */
	}

	bst_t *new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (parent == NULL) /* Tree is empty */
		*tree = new;
	else if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;

	return (new);
}
