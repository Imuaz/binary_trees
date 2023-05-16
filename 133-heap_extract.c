#include "binary_trees.h"

size_t count_nodes(const binary_tree_t *root);
heap_t *find_last_node(heap_t *root, size_t height, size_t level);
size_t get_tree_height(const binary_tree_t *root);
heap_t *heapify_down(heap_t *root);
void swap(heap_t *node1, heap_t *node2);

/**
 * count_nodes - counts the total number of nodes in a binary tree
 * @root: pointer to the root node of the binary tree
 * Return: total number of nodes
 */
size_t count_nodes(const binary_tree_t *root)
{
    if (root == NULL)
        return 0;

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

/**
 * find_last_node - finds the last node in the heap
 * @root: pointer to the root node of the heap
 * @height: height of the heap
 * @level: current level of the heap
 * Return: pointer to the last node in the heap
 */
heap_t *find_last_node(heap_t *root, size_t height, size_t level)
{
    if (root == NULL)
        return NULL;

    if (height == level)
    {
        if (root->left == NULL && root->right == NULL)
            return root;
        return NULL;
    }

    if (root->right == NULL)
        return find_last_node(root->left, height, level + 1);

    if (count_nodes(root->right) == (size_t)(1 << (height - level - 1)))
        return find_last_node(root->right, height, level + 1);
    return find_last_node(root->left, height, level + 1);
}

 /**
 * heapify_down - restores the max heap property by moving the node down the heap
 * @root: pointer to the root node of the heap
 * Return: pointer to the root node of the modified heap
 */
heap_t *heapify_down(heap_t *root)
{
    heap_t *current = root;

    while (1) {
        heap_t *max = current;
        heap_t *left = current->left;
        heap_t *right = current->right;

        if (left && left->n > max->n)
            max = left;

        if (right && right->n > max->n)
            max = right;

        if (max == current)
            break;

        int temp = current->n;
        current->n = max->n;
        max->n = temp;

        current = max;
    }

    return root;
}

/**
 * get_tree_height - calculates the height of a binary tree
 * @root: pointer to the root node of the binary tree
 * Return: height of the tree
 */
size_t get_tree_height(const binary_tree_t *root)
{
    size_t left_height, right_height;

    if (root == NULL)
        return 0;

    left_height = get_tree_height(root->left);
    right_height = get_tree_height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}


/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node, *temp, *current;
    int value;

    if (root == NULL || *root == NULL)
        return 0;

    current = *root;
    value = current->n;

    last_node = find_last_node(*root, get_tree_height(*root), 1);

    while (current->left && current->right)
    {
        if (count_nodes(current->left) > count_nodes(current->right))
            current = current->left;
        else
            current = current->right;
    }

    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;

        temp = *root;
        *root = last_node;
        last_node->parent = temp->parent;
        last_node->left = temp->left;
        last_node->right = temp->right;

        if (temp->left)
            temp->left->parent = last_node;
        if (temp->right)
            temp->right->parent = last_node;

        free(temp);

        *root = heapify_down(*root);
    }
    else
    {
        free(*root);
        *root = NULL;
    }

    return value;
}
