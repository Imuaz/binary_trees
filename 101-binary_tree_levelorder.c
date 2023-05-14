#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Create an array to store the nodes at each level */
	binary_tree_t *level[1000];  /* Maximum tree height assumed to be 1000 */
	int front = 0, rear = -1;

	/* Enqueue the root node */
	level[++rear] = (binary_tree_t *)tree;

	if (tree == NULL || func == NULL)
		return;

	/* Perform level-order traversal */
	while (front <= rear)
	{
		binary_tree_t *current = level[front++];

		func(current->n);

		/* Enqueue the left and right child nodes, if exist */
		if (current->left != NULL)
			level[++rear] = current->left;
		if (current->right != NULL)
			level[++rear] = current->right;
	}
}
