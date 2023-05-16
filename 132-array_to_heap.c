#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;

	if (!array || size == 0)
		return (NULL);

	heap_t *root = NULL;
	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}
	return (root);
}
