
# Heap: Properties and Array Representation

## 1. What is a Heap?

A **heap** is a specialised tree-based data structure that satisfies two conditions:

1. It is a **complete binary tree**.
2. It follows the **heap-order property**.

A heap is commonly used when we need quick access to the maximum or minimum element. It is also the usual underlying data structure for a priority queue.

## 2. Complete Binary Tree

A binary tree is complete when:

- Every level, except possibly the last, is completely filled.
- The last level is filled from left to right, without gaps.

A heap must be complete. This shape allows us to store its elements compactly in an array without using pointers between nodes.

Example:

```text
             40
           /    \
         30      35
        /  \    /  \
      10   15  20   25
```

This is a complete binary tree.

## 3. Types of Heap

### Max Heap

In a **Max Heap**, every parent is greater than or equal to its children.

- The largest element is at the root.
- Every parent-child relationship must satisfy `parent >= child`.
- The left and right subtrees are not necessarily sorted relative to each other.

### Min Heap

In a **Min Heap**, every parent is less than or equal to its children.

- The smallest element is at the root.
- Every parent-child relationship must satisfy `parent <= child`.

The examples and implementation in this section use a **Max Heap**, unless stated otherwise.

## 4. Array Representation

Since a heap is a complete binary tree, its nodes can be stored level by level in an array.

For a **0-based array** (root at index `0`), the relationships for a node at index `i` are:

| Node | Index |
|---|---:|
| Parent | `(i - 1) / 2` |
| Left child | `2*i + 1` |
| Right child | `2*i + 2` |

Integer division is used for the parent formula. The root has no parent.

For a **1-based array** (root at index `1`):

| Node | Index |
|---|---:|
| Parent | `i / 2` |
| Left child | `2*i` |
| Right child | `2*i + 1` |

Be careful not to mix the two indexing systems in one implementation.

## 5. Important Properties

1. A heap is a complete binary tree.
2. A heap is usually implemented using an array.
3. In a Max Heap, the maximum element is at the root; in a Min Heap, the minimum element is at the root.
4. Duplicate values are allowed.
5. The height of a heap with `n` nodes is `O(log n)` because the tree is complete.
6. A heap is designed for priority access, not for searching an arbitrary value. Searching for an arbitrary element can take `O(n)` time.
7. The heap property only compares a node with its parent and children. It does not make the whole array sorted.

## 6. Height and Complexity

A complete binary tree with `n` nodes has height `O(log n)`.

For a heap:

| Operation | Time complexity | Reason |
|---|---:|---|
| Access root | `O(1)` | Root is at index `0` (or `1` in 1-based representation) |
| Insert | `O(log n)` | An element may move from a leaf to the root |
| Delete root | `O(log n)` | The replacement root may move down the tree |
| Search arbitrary value | `O(n)` | Heap order does not fully sort the elements |

The insertion and deletion procedures restore the heap property by moving an element along the height of the tree. Since the height is logarithmic, both operations take `O(log n)` time.

## 7. Heap vs. Binary Search Tree

| Heap | Binary Search Tree |
|---|---|
| Complete binary tree | Need not be complete |
| Parent-child heap order | Left subtree keys are smaller and right subtree keys are larger (for the usual distinct-key BST convention) |
| Root gives maximum in Max Heap | Minimum/maximum found by following a path |
| Arbitrary search is `O(n)` | Search is `O(h)`; balanced BSTs give `O(log n)` |

**Remember:** A heap is not a sorted tree. It only guarantees the parent-child ordering required by its heap type.

