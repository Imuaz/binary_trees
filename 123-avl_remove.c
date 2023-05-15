#include "binary_trees.h"
int successor(bst_t *node);
void avl_balance(avl_t **tree);


/**
 * successor - Finds the minimum value in the right subtree of a node.
 * @node: Pointer to the node to find the successor.
 * Return: The minimum value in the right subtree.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * avl_balance - Balances the AVL tree if necessary after node removal.
 * @tree: Pointer to the pointer of the tree to balance.
 */
void avl_balance(avl_t **tree)
{
	int b_value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	avl_balance(&(*tree)->left);
	avl_balance(&(*tree)->right);
	b_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * remove_type - Removes a node from the tree depending on its children.
 * @root: Pointer to the node to remove.
 * Return: 0 if the node has no children, or a new value if it has.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: Pointer to the root of the tree.
 * @value: Value of the node to remove.
 * Return: The modified tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: a pointer to the root node of the tree for removing a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	avl_balance(&root_a);
	return (root_a);
}
