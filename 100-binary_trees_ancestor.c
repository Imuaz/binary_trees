#include "binary_trees.h"

/**
 * binary_trees_ancestor(const - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first nodes
 * @second: a pointer to the second nodes
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * or NULL If no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancest1, *ancest2;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ancest1 = first->parent;
	ancest2 = second->parent;

	if (first == ancest2 || !ancest1 || (!ancest1->parent && ancest2))
		return (binary_trees_ancestor(first, ancest2));
	else if (ancest1 == second || !ancest2 || (!ancest2->parent && ancest1))
		return (binary_trees_ancestor(ancest1, second));
	return (binary_trees_ancestor(ancest1, ancest2));
}
