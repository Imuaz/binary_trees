#include "binary_trees.h"

void swap(heap_t *a, heap_t *b);
heap_t *find_last_node(heap_t *root, size_t size);
heap_t *heapify_down(heap_t *root);
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * swap - swaps the values of two heap nodes
 * @a: first node
 * @b: second node
 */
void swap(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * find_last_node - finds the last node in the heap
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 * Return: pointer to the last node
 */
heap_t *find_last_node(heap_t *root, size_t size)
{
    size_t index = size;
    size_t level = 0;

    while (index > 0)
    {
        index >>= 1;
        level++;
    }

    index = size - (1 << (level - 1));

    while (level > 1)
    {
        if (index & 1)
            root = root->right;
        else
            root = root->left;

        index >>= 1;
        level--;
    }

    return root;
}

/**
 * heapify_down - restores the max heap property by moving the node down the heap
 * @root: pointer to the root node of the heap
 * Return: pointer to the root node of the modified heap
 */
heap_t *heapify_down(heap_t *root)
{
    heap_t *current = root;

    while (1)
    {
        heap_t *max = current;
        heap_t *left = current->left;
        heap_t *right = current->right;

        if (left && left->n > max->n)
            max = left;

        if (right && right->n > max->n)
            max = right;

        if (max == current)
            break;

        swap(current, max);
        current = max;
    }

    return root;
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return 0;

    int value = (*root)->n;
    size_t size = binary_tree_size(*root);

    if (size == 1)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    heap_t *last_node = find_last_node(*root, size);
    swap(*root, last_node);

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);

    *root = heapify_down(*root);

    return value;
}
