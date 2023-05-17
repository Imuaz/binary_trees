#include "binary_trees.h"


/**
 * binary_swap - swaps two nodes in binary tree
 * @a: first node
 * @b: second node
 * Return: pointer to root
 */
bst_t *binary_swap(bst_t *a, bst_t *b)
{
	bst_t a_copy = INIT_NODE;

	a_copy.n = a->n;
	a_copy.parent = a->parent;
	a_copy.left = a->left;
	a_copy.right = a->right;
	a->parent = b;
	a->left = b->left;
	a->right = b->right;

	if (b->left)
		b->left->parent = a;
	if (b->right)
		b->right->parent = a;
	b->parent = a_copy.parent;
	if (a_copy.parent)
	{
		if (a == a_copy.parent->left)
			a_copy.parent->left = b;
		else
			a_copy.parent->right = b;
	}
	if (b == a_copy.left)
	{
		b->left = a;
		b->right = a_copy.right;

		if (a_copy.right)
			a_copy.right->parent = b;
	}
	else if (b == a_copy.right)
	{
		b->right = a;
		b->left = a_copy.left;
		if (a_copy.left)
			a_copy.left->parent = b;
	}
	while (b->parent)
		b = b->parent;
	return (b);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap_head - helper function to swap head and node
 * @head: pointer to head
 * @node: pointer to node
 * Return: pointer to severed head of tree
 */
heap_t *swap_head(heap_t *head, heap_t *node)
{
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	}
	else
		node->parent->right = NULL;
	node->parent = NULL;
	node->left = head->left;
	node->right = head->right;
	if (head->left)
		head->left->parent = node;
	if (head->right)
		head->right->parent = node;
	return (head);
}

/**
 * perc_down - percolate head into correct position
 * @node: pointer to head
 * Return: pointer to head of tree
 */
heap_t *perc_down(heap_t *node)
{
	int max;
	heap_t *next = node;

	if (!node)
		return (NULL);
	max = node->n;
	if (node->left)
		max = MAX(node->left->n, max);
	if (node->right)
		max = MAX(node->right->n, max);
	if (node->left && max == node->left->n)
		next = node->left;
	else if (node->right && max == node->right->n)
		next = node->right;
	if (next != node)
	{
		binary_swap(node, next);
		perc_down(node);
	}
	return (next);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root of heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	size_t bin_size, i;
	char *bin_rep, bin_digit, bin_buff[50];
	int extracted_value;
	heap_t *node1, *head;

	if (!root || !*root)
		return (0);
	SETUP_NODE_BLOCK;

	if (bin_size == 1)
	{
		FREE_NODE_BLOCK;
		return (extracted_value);
	}
	do {
		CONVERT_LOOP;
	} while (bin_size);
	for (i = 1; i < strlen(bin_rep); i++)
	{
		bin_digit = bin_rep[i];
		if (i == strlen(bin_rep) - 1)
		{
			if (bin_digit == '1')
			{
				node1 = node1->right;
				break;
			}
			else if (bin_digit == '0')
			{
				node1 = node1->left;
				break;
			}
		}
		if (bin_digit == '1')
			node1 = node1->right;
		else if (bin_digit == '0')
			node1 = node1->left;
	}
	SWAP_HEAD_BLOCK;
	return (extracted_value);
}
