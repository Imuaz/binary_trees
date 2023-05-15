#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **root, avl_t *parent, avl_t **new_node,
		int value);
/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: the measured height, 0 If tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height, right_height;

		left_height = tree->left ? 1 + height(tree->left) : 1;
		right_height = tree->right ? 1 +  height(tree->right) : 1;

		if (left_height > right_height)
		{
			return (left_height);
		}
		return (right_height);
	}
	return (0);
}
/**
 * avl_balance_factor - Calculates the balance factor of an AVL tree node.
 * @tree: A pointer to the node of the AVL tree.
 *
 * Return: The balance factor of the AVL tree node, or 0 if the node is NULL.
 */
int avl_balance_factor(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		return (height(tree->left) - height(tree->right));
	}
	return (0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @root: A double pointer to the root node of the AVL tree.
 * @parent: A pointer to the parent node.
 * @new_node: A double pointer to store the newly created node.
 * @value: The value to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **root, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	/* Insert into an empty tree */
	if (*root == NULL)
		return (*new_node = binary_tree_node(parent, value));
	/* Recursively insert into the left subtree if value is smaller */
	if ((*root)->n > value)
	{
		(*root)->left = avl_insert_recursive(&(*root)->left, *root, new_node, value);
		if ((*root)->left == NULL)
			return (NULL);
	}
	/* Recursively insert into the right subtree if value is larger */
	else if ((*root)->n < value)
	{
		(*root)->right = avl_insert_recursive(&(*root)->right, *root,
				new_node, value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	/* If value already exists, return the existing node */
	else
		return (*root);
	/* Check balance factor and perform rotations if necessary */
	balance_factor = avl_balance_factor(*root);
	if (balance_factor > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance_factor < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance_factor > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	return (*root);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}
