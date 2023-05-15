#include "binary_trees.h"

avl_t *sorted_array_to_avl_helper(int *array, int start, int end);
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1));
}

/**
 * sorted_array_to_avl_helper - Helper function to build AVL tree
 * from sorted array.
 * @array: Pointer to the first element of the array.
 * @start: Index of the start element of the current subarray.
 * @end: Index of the end element of the current subarray.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
	int mid;
	avl_t *node;

	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));

	if (start > end)
		return (NULL);

	if (node == NULL)
		return (NULL);

	node->n = array[mid];
	node->left = sorted_array_to_avl_helper(array, start, mid - 1);
	node->right = sorted_array_to_avl_helper(array, mid + 1, end);

	if (node->left != NULL)
		node->left->parent = node;
	if (node->right != NULL)
		node->right->parent = node;

	return (node);
}
