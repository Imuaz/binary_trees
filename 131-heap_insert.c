#include "binary_trees.h"

void insert(heap_t **root, heap_t *node);
size_t binary_tree_size(const binary_tree_t *tree);
char *convert(unsigned long int num, int base, int lowercase);
bst_t *swap(bst_t *node1, bst_t *node2);

/**
 * insert - Inserts a node into the correct location in a max heap
 * @root: Double pointer to the root of the max heap
 * @node: Pointer to the node to be inserted
 */
void insert(heap_t **root, heap_t *node)
{
	heap_t *current;
	int heap_size;
	unsigned int i;
	char *binary_size;
	char binary_digit;

	current = *root;
	heap_size = binary_tree_size(current) + 1;
	binary_size = convert(heap_size, 2, 1);
	
	for (i = 1; i < strlen(binary_size); i++)
	{
		binary_digit = binary_size[i];

		/*If it's the last binary digit*/
		if (i == strlen(binary_size) - 1)
		{
			if (binary_digit == '1')
			{
				/*Insert node as the right child of the current node*/
				node->parent = current;
				current->right = node;
				break;
			}
			else if (binary_digit == '0')
			{
				/*Insert node as the left child of the current node*/
				node->parent = current;
				current->left = node;
				break;
			}
		}

		/*Traverse to the next node based on the binary digit*/
		if (binary_digit == '1')
			current = current->right;

		else if (binary_digit == '0')
			current = current->left;
	}
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root of the binary tree
 *
 * Return: The size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * convert - Converts a number to a string representation in a given base
 * @num: The input number to convert
 * @base: The base to convert the number to
 * @lowercase: Flag to indicate if hexa values need to be lowercase
 * (1) or uppercase (0)
 * Return: Pointer to the resulting string.
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep, buffer[50];
	char *ptr, *c;

	rep = "0123456789ABCDEF";

	ptr = &buffer[sizeof(buffer) - 1];
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num > 0);

	if (lowercase)
	{
		/*Convert uppercase letters to lowercase*/
		for (c = ptr; *c != '\0'; ++c)
		{
			if (*c >= 'A' && *c <= 'F')
			{
				*c = *c - 'A' + 'a';
			}
		}
	}
	return (ptr);
}

/**
 * swap - Swaps two nodes in a binary tree
 * @node1: First node to swap
 * @node2: Second node to swap
 *
 * Return: Pointer to the new root node of the tree after swapping.
 */
bst_t *swap(bst_t *node1, bst_t *node2) {
	bst_t *parent1, *left1, *right1;

	/*Store the original parent and children of node1*/
	parent1 = node1->parent;
	left1 = node1->left;
	right1 = node1->right;

	/*Update node1's parent and children*/
	node1->parent = node2;
	node1->left = node2->left;
	node1->right = node2->right;

	if (node2->left)
		node2->left->parent = node1;
	if (node2->right)
		node2->right->parent = node1;

	/*Update node2's parent*/
	node2->parent = parent1;
	if (parent1)
	{
		if (node1 == parent1->left)
			parent1->left = node2;
		else
			parent1->right = node2;
	}

	/*Update node2's children*/
	if (node2->left == node1)
	{
		node2->left = node1;
		node2->right = right1;
		if (right1)
			right1->parent = node2;
	}
	else if (node2->right == node1)
	{
		node2->right = node1;
		node2->left = left1;
		if (left1)
			left1->parent = node2;
	}

	/*Find and return the new root node*/
	while (node2->parent)
		node2 = node2->parent;

	return (node2);
}

/**
 * heap_insert - Inserts a value into a max binary heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to be inserted
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current;

	if (!root)
		return (NULL);

	/*Create a new node*/
	new_node = malloc(sizeof(heap_t));

	if (!new_node)
		return (NULL);

	/*Initialize the new node*/
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	/*If the root is empty, set the new node as the root*/
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

    /*Start from the root and insert the new node in the correct location*/
	current = *root;
	insert(&current, new_node);

	/*Swap the new node with its parent until the heap property is satisfied*/
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap(new_node, new_node->parent);

		/*If the new node becomes the new root, update the root pointer*/
		if (new_node->parent->parent == NULL)
			*root = new_node;
		new_node = new_node->parent;
	}
	return (new_node);
}
