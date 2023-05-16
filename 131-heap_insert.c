#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes in a binary tree
 * @node1: First node to swap
 * @node2: Second node to swap
 *
 * Return: Pointer to the new root node after swapping
 */
bst_t *swap_nodes(bst_t *node1, bst_t *node2)
{
	bst_t temp_node = INIT_NODE;

	temp_node.n = node1->n;
	temp_node.parent = node1->parent;
	temp_node.left = node1->left;
	temp_node.right = node1->right;

	node1->parent = node2;
	node1->left = node2->left;
	node1->right = node2->right;

	if (node2->left)
		node2->left->parent = node1;
	if (node2->right)
		node2->right->parent = node1;

	node2->parent = temp_node.parent;
	if (temp_node.parent)
	{
		if (node1 == temp_node.parent->left)
			temp_node.parent->left = node2;
		else
			temp_node.parent->right = node2;
	}

	if (node2 == temp_node.left)
	{
		node2->left = node1;
		node2->right = temp_node.right;
		if (temp_node.right)
			temp_node.right->parent = node2;
	}
	else if (node2 == temp_node.right)
	{
		node2->right = node1;
		node2->left = temp_node.left;
		if (temp_node.left)
			temp_node.left->parent = node2;
	}

	while (node2->parent)
		node2 = node2->parent;

	return (node2);
}

/**
 * convert_to_string - Converts a number to a string representation in a given base
 * @num: The number to convert
 * @base: The base to convert the number to
 * @lowercase: Flag to indicate if hexadecimal values need to be lowercase
 *
 * Return: Pointer to the resulting string
 */
char *convert_to_string(unsigned long int num, int base, int lowercase)
{
	static char buffer[50];
	const char *rep;
	char *ptr;

	rep = lowercase ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[sizeof(buffer) - 1];
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num > 0);

	return (ptr);
}

/**
 * get_binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root of the binary tree
 *
 * Return: The size of the binary tree
 */
size_t get_binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + get_binary_tree_size(tree->left) + get_binary_tree_size(tree->right));
}

/**
 * insert_node - helper function to insert a node in the correct location
 * @root: double pointer to the root of the max heap
 * @node: node to insert
 */
void insert_node(heap_t **root, heap_t *node)
{
	unsigned int i;
	char checker;
	char *binary;
	int size;
	heap_t *tmp = *root;

	size = get_binary_tree_size(tmp) + 1;
	binary = convert_to_string(size, 2, 1);
	for (i = 1; i < strlen(binary); i++)
	{
		checker = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (checker == '1')
			{
				node->parent = tmp;
				tmp->right = node;
			}
			else if (checker == '0')
			{
				node->parent = tmp;
				tmp->left = node;
			}
			break;
		}
		if (checker == '1')
			tmp = tmp->right;
		else if (checker == '0')
			tmp = tmp->left;
	}
}

/**
 * heap_insert - inserts a value in a Max Binary Heap
 * @root: double pointer to the root of the tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent, *current;

	if (!root)
		return (NULL);

	new_node = calloc(1, sizeof(heap_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	insert_node(root, new_node);
	current = new_node;

	while (current->parent && current->n > current->parent->n)
	{
		parent = current->parent;
		swap_nodes(parent, current);
		if (*root == parent)
			*root = current;
	}

	return (new_node);
}
