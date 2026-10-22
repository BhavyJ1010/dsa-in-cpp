
# Binary Tree Theory

## 1. Basic Terminology

- **Node:** An element containing data and links to its children.
- **Root:** The topmost node of a tree.
- **Parent:** A node that has a child.
- **Child:** A node directly below another node.
- **Siblings:** Nodes having the same parent.
- **Leaf node (external node):** A node with no children.
- **Internal node:** A node with at least one child.
- **Degree of a node:** Number of children of that node.
- **Level:** The position of a node in the tree. Here, the root is at level 1.
- **Height of a tree:** Number of nodes on the longest root-to-leaf path. An empty tree has height 0.
- **Subtree:** A node together with all its descendants.

A binary tree has at most two children per node: left child and right child.

## 2. Number of Binary Trees Using N Nodes

The number of structurally different binary trees with `n` nodes is the nth Catalan number:

C(n) = (1 / (n + 1)) * (2n choose n)

Equivalently:

C(n) = (2n)! / ((n + 1)! * n!)

Examples:

- n = 0: 1 tree (empty tree)
- n = 1: 1 tree
- n = 2: 2 trees
- n = 3: 5 trees
- n = 4: 14 trees
- n = 5: 42 trees

This counts different tree structures, not different arrangements of node values.

## 3. Height vs Number of Nodes

For a binary tree of height `h`, where height is measured in nodes:

- Maximum nodes at level `i` = 2^(i - 1)
- Maximum total nodes = 2^h - 1
- Minimum nodes for a non-empty tree of height `h` = h
- Minimum possible height for `n` nodes = ceil(log2(n + 1))
- Maximum possible height for `n` nodes = n

The maximum-node case is a perfect binary tree. The maximum-height case is a completely skewed tree.

## 4. Internal Nodes vs External Nodes

For a binary tree with `n` actual nodes:

- Every node has two child-pointer positions.
- There are `2n` child-pointer positions in total.
- Exactly `n - 1` of these point to actual child nodes.
- The remaining `n + 1` are null child pointers.

If external nodes means null links, their number is `n + 1`.

Do not confuse null links with leaf nodes. A leaf is an actual node; a null link is an empty child position.

## 5. Strict Binary Tree

A strict binary tree is one in which every node has either:

- Zero children (a leaf), or
- Exactly two children.

A node with only one child is not allowed.

Let:
- `n0` = number of leaf nodes
- `n2` = number of nodes with two children
- `n` = total number of nodes

For a non-empty strict binary tree:

- `n0 = n2 + 1`
- `n = n0 + n2`
- `n = 2*n2 + 1`
- `n = 2*n0 - 1`

Therefore, the total number of nodes in a strict binary tree is always odd.

## 6. Height vs Nodes in a Strict Binary Tree

For a strict binary tree of height `h`:

- Minimum nodes = 2h - 1
- Maximum nodes = 2^h - 1

The minimum occurs when each internal node on the longest path has one leaf as its other child. The maximum occurs when every level is completely filled.

## 7. Internal vs External Nodes in Strict Binary Trees

In a non-empty strict binary tree:

- Every internal node has exactly two children.
- Every leaf has zero children.
- Number of leaves = number of internal nodes + 1.

If `i` is the number of internal nodes and `l` is the number of leaves:

`l = i + 1`

This is a property of strict binary trees, not arbitrary binary trees.

## 8. N-ary Trees

An n-ary tree allows each node to have at most `n` children.

For a tree of height `h`, with the root at level 1:

- Maximum nodes at level `i` = n^(i - 1)
- Maximum total nodes = (n^h - 1) / (n - 1), for n > 1

For a binary tree, `n = 2`, giving `2^h - 1` as the maximum total number of nodes.

If each node reserves space for `n` child pointers, unused child-pointer positions may waste memory when nodes have fewer children.

## 9. Full vs Complete Binary Tree

Terminology can vary between textbooks, so use the definitions taught in your course.

**Full (perfect) binary tree:**
- Every internal node has exactly two children.
- All leaves are at the same level.
- Every level is completely filled.
- For height `h`, total nodes = `2^h - 1`.

**Complete binary tree:**
- Every level except possibly the last is completely filled.
- Nodes at the last level are filled from left to right, without gaps.

A complete binary tree need not have all leaves at the same level.

## 10. Strict vs Complete Binary Tree

**Strict binary tree:**
- Every node has either zero or two children.
- Nodes with exactly one child are not allowed.
- Levels need not be completely filled.

**Complete binary tree:**
- All levels before the last are full.
- The last level is filled from left to right.
- A node may have only one child, provided the complete-tree shape is maintained.

Thus, strict and complete describe different properties. A tree can satisfy both, but neither definition automatically guarantees the other.

## Quick Formula Revision

| Property | Formula |
|---|---|
| Maximum nodes at level `i` in a binary tree | `2^(i-1)` |
| Maximum nodes at height `h` | `2^h - 1` |
| Minimum nodes at height `h` | `h` |
| Maximum height for `n` nodes | `n` |
| Minimum height for `n` nodes | `ceil(log2(n+1))` |
| Null child links in a binary tree with `n` nodes | `n+1` |
| Strict binary tree leaves | `n0 = n2 + 1` |
| Strict tree total nodes | `n = 2*n2 + 1` |
| Maximum nodes in an n-ary tree of height `h` | `(n^h - 1)/(n - 1)`, for branching factor `n > 1` |
| Number of binary tree structures with `n` nodes | Catalan number `C(n)` |
