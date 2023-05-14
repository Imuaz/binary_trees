#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first nodes
 * @second: a pointer to the second nodes
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * or NULL If no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor1, *ancestor2;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ancestor1 = first->parent;
	ancestor2 = second->parent;

	while (ancestor1)
	{
		if (ancestor1 == second)
			return (ancestor1);
		ancestor2 = second->parent;

		if (!ancestor2)
			return (binary_trees_ancestor(ancestor1, second));

		ancestor1 = ancestor1->parent;
	}
	return (NULL);
}
