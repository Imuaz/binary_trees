# 0x1D. C - Binary trees:zero::one:

**INTRODUCTION**

The project covered several key aspects of binary trees, including their definition and structure. It explained the difference between a binary tree and a Binary Search Tree (BST). Additionally, it explored the potential gains in terms of time complexity compared to linked lists. The project also discussed important properties of binary trees, such as depth, height, and size. Moreover, it delved into various traversal methods used to navigate through binary trees. Finally, the project covered different types of binary trees, including complete, full, perfect, and balanced binary trees. Overall, the project provided a comprehensive understanding of binary trees and their characteristics.

## Resources:books:

- [Binary tree](https://en.m.wikipedia.org/wiki/Binary_tree)(note the first line:_Not to be confused with B-tree_.)
- [Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)
- [Tree Traversal](https://www.programiz.com/dsa/tree-traversal)
- [Binary Search Tree](https://en.m.wikipedia.org/wiki/Binary_search_tree)
- [Data structures: Binary Tree](https://youtu.be/H5JubkIy_p8)

## Requirements:pushpin:

**General**
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A mandatory [README.md](./README.md) file, at the root of the folder of the project.
- The code should use the `Betty style`. It will be checked using `betty-style.pl` and `betty-doc.pl`
- It is not allowed to use global variables
- No more than 5 functions per file
- It is allowed to use the standard library
- The prototypes of all functions should be included in a header file called `binary_trees.h`
- All header files should be include guarded

## Header files:open_file_folder:
- [binary_trees.h](./binary_trees.h): Header file containing the prototypes of all functions and the data structures and types definition for binary trees.


|File|Prototype|
|----|---------|
|`0-binary_tree_node.c`|`binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`|
|`1-binary_tree_insert_left.c`|`binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`|
|`2-binary_tree_insert_right.c`|`binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`|
|`3-binary_tree_delete.c`|`void binary_tree_delete(binary_tree_t *tree);`|
|`4-binary_tree_is_leaf.c`|`int binary_tree_is_leaf(const binary_tree_t *node);`|
|`5-binary_tree_is_root.c`|`int binary_tree_is_root(const binary_tree_t *node);`|
|`6-binary_tree_preorder.c`|`void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`|
|`7-binary_tree_inorder.c`|`void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`|
|`8-binary_tree_postorder.c`|`void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`|
|`9-binary_tree_height.c`|`size_t binary_tree_height(const binary_tree_t *tree);`|
|`10-binary_tree_depth.c`|`size_t binary_tree_depth(const binary_tree_t *tree);`|
|`11-binary_tree_size.c`|`size_t binary_tree_size(const binary_tree_t *tree);`|
|`12-binary_tree_leaves.c`|`size_t binary_tree_leaves(const binary_tree_t *tree);`|
|`13-binary_tree_nodes.c`|`size_t binary_tree_nodes(const binary_tree_t *tree);`|
|`14-binary_tree_balance.c`|`int binary_tree_balance(const binary_tree_t *tree);`|
|`15-binary_tree_is_full.c`|`int binary_tree_is_full(const binary_tree_t *tree);`|
|`16-binary_tree_is_perfect.c`|`int binary_tree_is_perfect(const binary_tree_t *tree);`|
|`17-binary_tree_sibling.c`|`binary_tree_t *binary_tree_sibling(binary_tree_t *node);`|
|`18-binary_tree_uncle.c`|`binary_tree_t *binary_tree_uncle(binary_tree_t *node);`|
|`100-binary_trees_ancestor.c`|`binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);`|
|`101-binary_tree_levelorder.c`|`void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));`|
|`102-binary_tree_is_complete.c`|`int binary_tree_is_complete(const binary_tree_t *tree);`|
|`103-binary_tree_rotate_left.c`|`binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);`|
|`104-binary_tree_rotate_right.c`|`binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);`|
|`110-binary_tree_is_bst.c`|`int binary_tree_is_bst(const binary_tree_t *tree);`|
|`111-bst_insert.c`, `0-binary_tree_node.c`|`bst_t *bst_insert(bst_t **tree, int value);`|
|`112-array_to_bst.c`, `111-bst_insert.c`, `0-binary_tree_node.c`|`bst_t *array_to_bst(int *array, size_t size);`|
|`113-bst_search.c`|`bst_t *bst_search(const bst_t *tree, int value);`|
|`114-bst_remove.c`|`bst_t *bst_remove(bst_t *root, int value);`|
|`115-O`|`-`|
|`120-binary_tree_is_avl.c`|`int binary_tree_is_avl(const binary_tree_t *tree);`|
|`121-avl_insert.c`, `14-binary_tree_balance.c`, `103-binary_tree_rotate_left.c`, `104-binary_tree_rotate_right.c`, `0-binary_tree_node.c`|`avl_t *avl_insert(avl_t **tree, int value);`|
|`123-avl_remove.c`, `14-binary_tree_balance.c`, `103-binary_tree_rotate_left.c`, `104-binary_tree_rotate_right.c`|`avl_t *avl_remove(avl_t *root, int value);`|
|`124-sorted_array_to_avl.c`, `0-binary_tree_node.c`|`avl_t *sorted_array_to_avl(int *array, size_t size);`|
|`125-O`|`-`|
|`130-binary_tree_is_heap.c`|`int binary_tree_is_heap(const binary_tree_t *tree);`|
|`131-heap_insert.c`, `0-binary_tree_node.c`|`heap_t *heap_insert(heap_t **root, int value)`|
|`132-array_to_heap.c`, `131-heap_insert.c`, `0-binary_tree_node.c`|`heap_t *array_to_heap(int *array, size_t size);`|
|`133-heap_extract.c`|`int heap_extract(heap_t **root);`|
|`134-heap_to_sorted_array.c`, `133-heap_extract.c`|`int *heap_to_sorted_array(heap_t *heap, size_t *size);`|
|`135-O`||

 **Data structures**
 The following data structures and types  are use for binary trees,and are included the header file.
- Basic Binary Tree:
```
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```
- Binary Search Tree:
```
typedef struct binary_tree_s bst_t;
```
- AVL Tree:
```
typedef struct binary_tree_s avl_t;
```
- Max Binary Heap:
```
typedef struct binary_tree_s heap_t;
```
**Note**: For tasks 0 to 23 (included), deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.

## Helper file:raised_hands:

- To match the given examples in the tasks, [this function](https://github.com/holbertonschool/0x1C.c) is given. The function is used only for visualization purposes. Thus, it has not been pushed to this repo. It may not be used during the correction.

## Tasks:page_with_curl:

**0. New node**
- [0-binary_tree_node.c](./0-binary_tree_node.c): A function that creates a binary tree node.
  - The parameter `parent` is a pointer to the parent node of the node to create
  - And the parameter `value` is the value to put in the new node
  - When created, a node does not have any child
  - It returns a pointer to the new node, or `NULL` on failure

**1. Insert left**
- [1-binary_tree_insert_left.c](./1-binary_tree_insert_left.c): A function that inserts a node as the left-child of another node.
  - The parameter `parent` is a pointer to the node to insert the left-child in
  - And `value` is the value to store in the new node
  - it returns a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`.
  - If `parent` already has a left-child, the new node takes its place, and the old left-child is set as the left-child of the new node.

**2. Insert right**
- [2-binary_tree_insert_right.c](./2-binary_tree_insert_right.c): A function that inserts a node as the right-child of another node.
  - The parameter `parent` is a pointer to the node to insert the right-child in
  - And `value` is the value to store in the new node
  - It returns a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`

**3. Delete**
- [3-binary_tree_delete.c](./3-binary_tree_delete.c): A function that deletes an entire binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to delete
  - If `tree` is NULL, does nothing

**4. Is leaf**
- [4-binary_tree_is_leaf.c](./4-binary_tree_is_leaf.c): A function that checks if a node is a leaf.
  - The parameter `node` is a pointer to the node to check
  - It returns `1` if `node` is a leaf, otherwise `0`
  - If `node` is `NULL`, return `0`

**5. Is root**
- [5-binary_tree_is_root.c](./5-binary_tree_is_root.c): A function that checks if a given node is a root.
  -  The parameter `node` is a pointer to the node to check
  -  it returns `1` if `node` is a root, otherwise `0`
  -  If `node` is `NULL`, it returns `0`.

**6. Pre-order traversal**
- [6-binary_tree_preorder.c](./6-binary_tree_preorder.c): A function that goes through a binary tree using pre-order traversal.
  - The parameter `tree` is a pointer to the root node of the tree to traverse
  - And `func` is a pointer to a function to call for each node. The value in the node is pass as a parameter to this function.
  - If `tree` or `func` is `NULL`, does nothing

**7. In-order traversal**
- [7-binary_tree_inorder.c](./7-binary_tree_inorder.c): A function that goes through a binary tree using in-order traversal.
  - The parameter `tree` is a pointer to the root node of the tree to traverse
  - And `func` is a pointer to a function to call for each node. The value in the node is pass as a parameter to this function.
  - If `tree` or `func` is `NULL`, does nothing

  **8. Post-order traversal**
  - [8-binary_tree_postorder.c](./8-binary_tree_postorder.c): A function that goes through a binary tree using post-order traversal.
    - The parameter `tree` is a pointer to the root node of the tree to traverse
    - And `func` is a pointer to a function to call for each node. The value in the node is pass as a parameter to this function.
    - If `tree` or `func` is `NULL`, does nothing

**9. Height**
- [9-binary_tree_height.c](./9-binary_tree_height.c): A function that measures the height of a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to measure the height.
  - If `tree` is `NULL`, the function must returns `0`

**10. Depth**
- [10-binary_tree_depth.c](./10-binary_tree_depth.c): A function that measures the depth of a node in a binary tree.
  - The parameter `tree` is a pointer to the node to measure the depth
  - If `tree` is `NULL`,the function returns `0`

**11. Size**
- [11-binary_tree_size.c](./11-binary_tree_size.c): A function that measures the size of a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to measure the size
  - If `tree` is `NULL`, the function returns `0`

**12. Leaves**
- [12-binary_tree_leaves.c](./12-binary_tree_leaves.c): A function that counts the leaves in a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to count the number of leaves
  - If `tree` is `NULL`, the function returns `0`
  - A `NULL` pointer is not a leaf
