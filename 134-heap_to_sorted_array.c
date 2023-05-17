#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted
 * array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers (in descending order),
 *         or NULL if @heap is NULL or if memory allocation fails
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	int extracted_value, index = 0;
	size_t heap_size;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;
	sorted_array = malloc(heap_size * sizeof(int));

	if (!sorted_array)
		return (NULL);

	while (heap)
	{
		extracted_value = heap_extract(&heap);
		sorted_array[index] = extracted_value;
		index++;
	}
	return (sorted_array);
}

