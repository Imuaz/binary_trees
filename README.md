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
- All header files should be include guarded

## Tests:100::heavy_check_mark:
- [tests](./tests): A folder containing the `main.c` files provided by ALX as examples for testing purposes.

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

**13. Nodes**
- [13-binary_tree_nodes.c](./13-binary_tree_nodes.c): A function that counts the nodes with at least 1 child in a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to count the number of nodes
  - If `tree` is `NULL`, the function returns `0`
  - A `NULL` pointer is not a node

**14. Balance factor**
- [14-binary_tree_balance.c](./14-binary_tree_balance.c): A function that measures the balance factor of a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to measure the balance factor
  - If `tree` is `NULL`, returns `0`

**15. Is full**
- [15-binary_tree_is_full.c](./15-binary_tree_is_full.c): A function that checks if a binary tree is full.
  - The parameter`tree` is a pointer to the root node of the tree to check
  - If `tree` is `NULL`, the function returns `0`

**16. Is perfect**
- [16-binary_tree_is_perfect.c](./16-binary_tree_is_perfect.c): A function that checks if a binary tree is perfect.
  - The parameter `tree` is a pointer to the root node of the tree to check
  - If `tree` is `NULL`, the function returns `0`

**17. Sibling**
- [17-binary_tree_sibling.c](./17-binary_tree_sibling.c): A function that finds the sibling of a node.
  - The parameter `node` is a pointer to the node to find the sibling
  - It returns a pointer to the sibling node
  - If `node` is `NULL` or the parent is `NULL`, it returns `NULL`
  - If `nod`d has no sibling, it return `NULL`

**18. Uncle**
- [18-binary_tree_uncle.c](./18-binary_tree_uncle.c): A function that finds the uncle of a node.
  - The parameter `node` is a pointer to the node to find the uncle
  - It returns a pointer to the uncle node
  - If `node` is `NULL`, it returnds `NULL`
  - If `node` has no uncle, it returns `NULL`

**19. Lowest common ancestor**
- [100-binary_trees_ancestor.c](./100-binary_trees_ancestor.c): A function that finds the lowest common ancestor of two nodes.
  - The parameter `first` is a pointer to the first node
  - And `second` is a pointer to the second node
  - the function returns a pointer to the lowest common ancestor node of the two given nodes
  - If no common ancestor was found, the function returns `NULL`

**20. Level-order traversal**
- [101-binary_tree_levelorder.c](./101-binary_tree_levelorder.c): A function that goes through a binary tree using level-order traversal.
  - The parameter `tree` is a pointer to the root node of the tree to traverse
  - And `func` is a pointer to a function to call for each node. The value in the node is pass as a parameter to this function.
  - If `tree` or `func` is `NULL`, does nothing

**21. Is complete**
- [102-binary_tree_is_complete.c](./102-binary_tree_is_complete.c): A function that checks if a binary tree is complete.
  - The parameter `tree` is a pointer to the root node of the tree to check
  - If `tree` is `NULL`, the function returns `0`

**22. Rotate left**
- [103-binary_tree_rotate_left.c](./103-binary_tree_rotate_left.c): A function that performs a left-rotation on a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to rotate
  - the function returns a pointer to the new root node of the tree once rotated

**23. Rotate right**
- [104-binary_tree_rotate_right.c](./104-binary_tree_rotate_right.c): A function that performs a right-rotation on a binary tree.
  - The parameter `tree` is a pointer to the root node of the tree to rotate
  - the function returns a pointer to the new root node of the tree once rotated

**24. Is BST**
- [110-binary_tree_is_bst.c](./110-binary_tree_is_bst.c): A function that checks if a binary tree is a valid [Binary Search Tree](https://en.m.wikipedia.org/wiki/Binary_search_tree)
  - The parameter `tree` is a pointer to the root node of the tree to check
  - the function returns `1` if `tree` is a valid BST, and `0` otherwise
  - If `tree` is `NULL`, it returns `0`
- Properties of a Binary Search Tree:
  - The left subtree of a node contains only nodes with values less than the node’s value
  - The right subtree of a node contains only nodes with values greater than the node’s value
  - The left and right subtree each must also be a binary search tree
  - There must be no duplicate values

**25. BST - Insert**
- [111-bst_insert.c](./111-bst_insert.c): A function that inserts a value in a Binary Search Tree
  - The parameter `tree` is a double pointer to the root node of the BST to insert the value
  - And `value` is the value to store in the node to be inserted
  - the function returns a pointer to the created node, or `NULL` on failure
  - If the address stored in tree is `NULL`, the created node becomes the root node.
  - If the value is already present in the tree, it is ignored
- the file `0-binary_tree_node.c` can be compiled during the correction

**26. BST - Array to BST**
- [112-array_to_bst.c](./112-array_to_bst.c): A function that builds a Binary Search Tree from an array
  - The parameter `array` is a pointer to the first element of the array to be converted
  - And `size` is the number of element in the array
  - the function returns a pointer to the root node of the created BST, or `NULL` on failure
  - If a value of the array is already present in the tree, the value wil be ignored
- The files `111-bst_insert.c` and `0-binary_tree_node.c` will be compiled during the correction

**27. BST - Search**
- [113-bst_search.c](./113-bst_search.c): A function that searches for a value in a Binary Search Tree
  - The parameter `tree` is a pointer to the root node of the BST to search
  - And `value` is the value to search in the tree
  - the function returns a pointer to the node containing a value equals to `value`
  - If `tree` is `NULL` or if nothing is found, it returns `NULL`

**28. BST - Remove**
- [114-bst_remove.c](./114-bst_remove.c): A function that removes a node from a Binary Search Tree
  - The parameter `root` is a pointer to the root node of the tree where the node will be removed
  - And `value` is the value to remove in the tree
  - once located, the node containing a value equals to `value` will be removed and freed
  - If the node to be deleted has two children, it will be replaced with its first `in-order` successor (not predecessor)
  - the function returns a pointer to the new root node of the tree after removing the desired value

**29. Big O #BST**
- [115-O](./115-O): file contains the average time complexities of those operations on a Binary Search Tree (one answer per line):
  - Inserting the value `n`
  - Removing the node with the value `n`
  - Searching for a node in a BST of size `n`

**30. Is AVL**
- [120-binary_tree_is_avl.c](./120-binary_tree_is_avl.c): A function that checks if a binary tree is a valid [AVL Tree](https://en.m.wikipedia.org/wiki/AVL_tree).
  - The parameter `tree` is a pointer to the root node of the tree to check
  - the function returns `1` if `tree` is a valid AVL Tree, and `0` otherwise
  - If `tree` is `NULL`, it returns `0`
- Properties of an AVL Tree:
  - An AVL Tree is a BST
  - The difference between heights of left and right subtrees cannot be more than one
  - The left and right subtrees must also be AVL trees

**31. AVL - Insert**
- [121-avl_insert.c](./121-avl_insert.c): A function that inserts a value in an AVL Tree
  - The parameter `tree` is a double pointer to the root node of the AVL tree for inserting the value
  - And `value` is the value to store in the node to be inserted
  - the function returns a pointer to the created node, or `NULL` on failure
  - If the address stored in tree is `NULL`, the created node becomes the root node.
  - The resulting tree after insertion, will be a balanced AVL Tree
- The files `14-binary_tree_balance.c`, `103-binary_tree_rotate_left.c`, `104-binary_tree_rotate_right.c` and `0-binary_tree_node.c` will be compiled during the correction

**32. AVL - Array to AVL**
- [122-array_to_avl.c](./122-array_to_avl.c): A function that builds an AVL tree from an array.
  - The parameter `array` is a pointer to the first element of the array to be converted
  - And `size` is the number of element in the array
  - the function returns a pointer to the root node of the created AVL tree, or `NULL` on failure
  - If a value of the array is already present in the tree, the value will be ignored
- the files `121-avl_insert.c`, `0-binary_tree_node.c`, `14-binary_tree_balance.c`, `103-binary_tree_rotate_left.c` and `104-binary_tree_rotate_right.c` will be compiled during the correction

**33. AVL - Remove**
- [123-avl_remove.c](./123-avl_remove.c): A function that removes a node from an AVL tree
  - The parameter `root` is a pointer to the root node of the tree for removing a node
  - And `value` is the value to remove in the tree
  - Once located, the node containing a value equals to value will be removed and freed
  - If the node to be deleted has two children, it will be replaced with its first `in-order successor` (not predecessor)
  - After deletion of the desired node, the tree will be rebalanced if necessary
  - the function returns a pointer to the new root node of the tree after removing the desired value, and after rebalancing
- The files `14-binary_tree_balance.c`, `103-binary_tree_rotate_left.c` and `104-binary_tree_rotate_right.c` will be compiled during the correction

**34. AVL - From sorted array**
- [124-sorted_array_to_avl.c](./124-sorted_array_to_avl.c): A function that builds an AVL tree from an array
  - The parameter `array` is a pointer to the first element of the array to be converted
  - And `size` is the number of element in the array
  - the function returns a pointer to the root node of the created AVL tree, or `NULL` on failure
  - it is assume that there will be no duplicate value in the array
  - it does not rotate
  - it is reqired only 2 functions in the file
- The file `0-binary_tree_node.c` will be compiled during the correction

**35. Big O #AVL Tree**
- [125-O](./125-O): file contains the average time complexities of those operations on an AVL Tree (one answer per line):
  - Inserting the value `n`
  - Removing the node with the value `n`
  - Searching for a node in an AVL tree of size `n`

**36. Is Binary heap**
- [130-binary_tree_is_heap.c](./130-binary_tree_is_heap.c): A function that checks if a binary tree is a valid [Max Binary Heap](https://en.m.wikipedia.org/wiki/Binary_heap)
  - The parameter `tree` is a pointer to the root node of the tree to check
  - the function returns `1` if `tree` is a valid Max Binary Heap, and `0` otherwise
  - If `tree` is `NULL`, it returns `0`
- Properties of a Max Binary Heap:
  - It’s a complete tree
  - In a Max Binary Heap, the value at root must be maximum among all values present in Binary Heap
  - The last property must be recursively true for all nodes in Binary Tree

**37. Heap - Insert**
- [131-heap_insert.c](./131-heap_insert.c): A function that inserts a value in Max Binary Heap.
  - The parameter `root` is a double pointer to the root node of the Heap to insert the value
  - And `value` is the value to store in the node to be inserted
  - the function returns a pointer to the created node, or `NULL` on failure
  - If the address stored in `root` is `NULL`, the created node becomes the root node.
  - it respects a `Max Heap` ordering
  - it is allowed to have up to 6 functions in the file
- The file `0-binary_tree_node.c` will be compiled during the correction

**38. Heap - Array to Binary Heap**
- [132-array_to_heap.c](./132-array_to_heap.c): A function that builds a Max Binary Heap tree from an array
  - The parameter `array` is a pointer to the first element of the array to be converted
  - And `size` is the number of element in the array
  - the function returns a pointer to the root node of the created Binary Heap, or `NULL` on failure
- The files `131-heap_insert.c` and `0-binary_tree_node.c` will be compiled during the correction

**39. Heap - Extract**
- [133-heap_extract.c](./133-heap_extract.c): A function that extracts the root node of a Max Binary Heap
  - The parameter `root` is a double pointer to the root node of heap
  - the function returns the value stored in the root node
  - The root node will be freed and replace with the last `level-order` node of the heap
  - Once replaced, the heap will be rebuilt if necessary
  - If the function fails, it returns `0`

**40. Heap - Sort**
- [134-heap_to_sorted_array.c](./134-heap_to_sorted_array.c): A function that converts a Binary Max Heap to a sorted array of integers.
  - The parameter `heap` is a pointer to the root node of the heap to convert
  - And `size` is an address to store the size of the array
  - it is assume `size` is a valid address
  - Since we are using Max Heap, the returned array will be sorted in descending order

**41. Big O #Binary Heap**
- [135-O](./135-O): file that contains the average time complexities of those operations on a Binary Heap (one answer per line):
  - Inserting the value `n`
  - Extracting the root node
  - Searching for a node in a binary heap of size `n`
