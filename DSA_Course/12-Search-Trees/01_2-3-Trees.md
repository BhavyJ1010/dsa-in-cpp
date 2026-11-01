
# 2-3 Trees

## 1. Introduction

A 2-3 Tree is a self-balancing search tree in which each internal node can have either:

- **2 children (2-node):** Contains one key.
- **3 children (3-node):** Contains two keys.

Unlike a Binary Search Tree, a node can store more than one key.

The main objective is to maintain balance automatically so that searching and insertion remain efficient.

## 2. Structure of Nodes

### 2-node

Contains one key and has two children.

```text
       [20]
       /  \
      L    R
```

- Keys in the left subtree are smaller than 20.
- Keys in the right subtree are greater than 20.

### 3-node

Contains two keys and has three children.

```text
        [20 | 40]
       /    |    \
      L     M     R
```

- Left subtree: keys < 20
- Middle subtree: 20 < keys < 40
- Right subtree: keys > 40

Keys inside every node are maintained in sorted order.

## 3. Properties of a 2-3 Tree

1. Every node is either a 2-node or a 3-node.
2. A 2-node contains one key and has two children.
3. A 3-node contains two keys and has three children.
4. All leaf nodes are at the same level.
5. Keys follow the search-tree ordering property.
6. The tree is always height-balanced.

The most important property is that **all leaves remain at the same depth**. This prevents the tree from becoming skewed.

## 4. Searching in a 2-3 Tree

Searching is similar to searching in a BST, except that a node may contain two keys.

Consider:

```text
             [20 | 40]
            /    |    \
        [10]   [30]   [50 | 60]
```

To search for 30:

1. Compare 30 with 20.
2. Since 30 > 20, move to the middle subtree.
3. Compare 30 with the key in that node.
4. Key found.

To search for 50:

1. Compare 50 with 20.
2. Move to the right subtree.
3. Compare 50 with 50.
4. Key found.

At each node, we determine which child can contain the required key.

## 5. Insertion in a 2-3 Tree

Insertion is performed at a leaf node.

The important rule is that a node cannot contain more than two keys.

### Case 1: Insertion into a 2-node

Suppose we insert 20 and then 10.

```text
Before:

    [20]

After:

   [10 | 20]
```

The new key is simply inserted in sorted order.

### Case 2: Insertion into a 3-node

Suppose the leaf contains:

```text
[10 | 20]
```

Now insert 30.

Temporarily, the keys become:

```text
[10 | 20 | 30]
```

This is an overflow because a 2-3 Tree node can contain at most two keys.

We split the node:

- The middle key (20) moves to the parent.
- The left key (10) becomes a separate node.
- The right key (30) becomes another separate node.

```text
Before:

       [10 | 20 | 30]

After:

           [20]
          /    \
        [10]   [30]
```

### Case 3: Splitting propagates upwards

Sometimes the parent is also a 3-node.

When the middle key is promoted, the parent may overflow as well.

In that case:

1. Split the parent.
2. Promote its middle key to its own parent.
3. Continue upwards if necessary.

If the root overflows, it is split and a new root is created.

This is how the tree grows in height while maintaining balance.

## 6. Example of Insertion

Insert the following keys:

```text
10, 20, 30, 40, 50
```

After inserting 10 and 20:

```text
[10 | 20]
```

Insert 30. The node overflows and splits:

```text
       [20]
       /  \
     [10] [30]
```

Insert 40:

```text
       [20]
       /  \
     [10] [30 | 40]
```

Insert 50. The right leaf overflows, and 40 is promoted:

```text
          [20 | 40]
         /    |    \
       [10]  [30]  [50]
```

Notice that all leaves are still at the same level.

## 7. Time Complexity

A 2-3 Tree remains balanced, so its height is logarithmic.

| Operation | Time Complexity |
|---|---|
| Search | O(log n) |
| Insertion | O(log n) |

Insertion may involve splitting multiple nodes, but at most one split per level.

## 8. Key Takeaways

- A 2-3 Tree is a balanced multiway search tree.
- A node stores either one or two keys.
- All leaves are at the same depth.
- Insertion takes place at a leaf.
- Overflow is handled by splitting and promoting the middle key.
- A root split increases the height of the tree by one.
