#include "binary_trees.h"

int is_complete_tree(const binary_tree_t *tree);
int is_complete_tree_helper(const binary_tree_t *tree,
		int index, int num_nodes);
int count_nodes(const binary_tree_t *tree);
int is_max_heap(const binary_tree_t *tree);
/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_complete_tree(tree))
		return (0);

	return (is_max_heap(tree));
}

/**
 * is_complete_tree - Checks if a binary tree is a complete tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a complete tree, 0 otherwise
 */
int is_complete_tree(const binary_tree_t *tree)
{
	int num_nodes;

	if (tree == NULL)
		return (1);

	num_nodes = count_nodes(tree);

	return (is_complete_tree_helper(tree, 0, num_nodes));
}

/**
 * is_complete_tree_helper - Helper function to check if a
 * binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Current index of the node being checked
 * @num_nodes: Total number of nodes in the tree
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_complete_tree_helper(const binary_tree_t *tree,
		int index, int num_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= num_nodes)
		return (0);

	return (is_complete_tree_helper(tree->left, 2 * index + 1, num_nodes) &&
			is_complete_tree_helper(tree->right, 2 * index + 2, num_nodes));
}

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
