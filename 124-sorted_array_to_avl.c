#include "binary_trees.h"

avl_t *sorted_array_to_avl_helper(int *arr, int start, int end, avl_t *parent);

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

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_helper - Helper function for sorted_array_to_avl
 * @arr: Input array
 * @start: Starting index
 * @end: Ending index
 * @parent: Pointer to parent node
 o* Return: Newly created node
 */
avl_t *sorted_array_to_avl_helper(int *arr, int start, int end, avl_t *parent)
{
	int middle;
	avl_t *new_node;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = arr[middle];
	new_node->parent = parent;
	new_node->left = sorted_array_to_avl_helper(arr, start, middle - 1, new_node);
	new_node->right = sorted_array_to_avl_helper(arr, middle + 1, end, new_node);

	return (new_node);
}
