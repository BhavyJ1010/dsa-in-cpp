
# Search Trees — Advanced Balanced Trees

*Conceptual notes and independently written implementations based on the lectures.*

## 1. Relationship Between 2-3-4 Trees and Red-Black Trees

A Red-Black Tree is a Binary Search Tree representation of a 2-3-4 Tree.

The important idea is that a multi-key node in a 2-3-4 Tree can be represented using multiple connected nodes in a Binary Search Tree.

A BLACK node represents the main key of the multi-key node, while RED child nodes represent additional keys belonging to that same node.

### 1.1 Representation of a 2-node

A 2-node contains one key.

2-3-4 Tree:

```text
       [20]
```

Red-Black Tree:

```text
       20(B)
```

A single BLACK node represents a 2-node.

### 1.2 Representation of a 3-node

A 3-node contains two keys.

2-3-4 Tree:

```text
       [20 | 40]
```

One possible Red-Black representation:

```text
          40(B)
         /
       20(R)
```

Another possible representation:

```text
       20(B)
            \
            40(R)
```

The RED node is connected to its BLACK parent, representing two keys belonging to the same conceptual multiway node.

### 1.3 Representation of a 4-node

A 4-node contains three keys.

2-3-4 Tree:

```text
       [20 | 40 | 60]
```

Red-Black representation:

```text
           40(B)
          /     \
       20(R)   60(R)
```

The BLACK node and its two RED children represent the three keys of the 4-node.

### 1.4 Summary

| 2-3-4 Tree node | Red-Black representation |
|---|---|
| 2-node | One BLACK node |
| 3-node | One BLACK node and one RED child |
| 4-node | One BLACK node and two RED children |

This representation explains why Red-Black Trees can maintain balance using only two colours.

**Important:** A RED link represents a connection within the same conceptual multiway node. A BLACK link separates different levels of the 2-3-4 Tree.

---

## 2. Why Red-Black Trees Remain Balanced

The five Red-Black properties prevent the tree from becoming excessively skewed.

The two most important properties for understanding its height are:

1. Every path from a node to its descendant NIL leaves contains the same number of BLACK nodes.
2. A RED node cannot have a RED child.

The first property ensures that every path has the same black height.

The second property prevents long sequences of consecutive RED nodes.

Therefore, the longest root-to-leaf path cannot be more than twice the shortest path in terms of node count.

This gives the Red-Black Tree its logarithmic height.

---

## 3. Black Height

The black height of a node is the number of BLACK nodes on any path from that node to a descendant NIL leaf.

For this definition, we include the starting node if it is BLACK, and include the NIL leaf.

Consider:

```text
             20(B)
            /     \
         10(R)   30(B)
                   \
                   40(R)
```

Every path from the root to a NIL leaf must contain the same number of BLACK nodes.

For example:

- Path through 10: 20(B), 10(R), NIL(B)
- Path through 30: 20(B), 30(B), NIL(B)
- Path through 40: 20(B), 30(B), 40(R), NIL(B)

These paths have equal black height.

Black height is important because it helps us mathematically establish the maximum height of a Red-Black Tree.

---

## 4. Height Analysis of Red-Black Trees

Let:

- n = number of internal nodes.
- h = height of the tree.
- bh = black height of the root.

### Step 1: Minimum number of nodes

A subtree with black height bh contains at least:

\[
n \geq 2^{bh}-1
\]

Therefore:

\[
n+1 \geq 2^{bh}
\]

Taking logarithms:

\[
bh \leq \log_2(n+1)
\]

### Step 2: Relationship between height and black height

Since two consecutive RED nodes are not allowed, at least every alternate node on a path must be BLACK.

Therefore:

\[
h \leq 2bh
\]

### Step 3: Combining both results

Substituting the bound on black height:

\[
h \leq 2\log_2(n+1)
\]

This is the maximum height bound of a Red-Black Tree.

Therefore:

\[
\boxed{h = O(\log n)}
\]

This guarantees logarithmic time complexity for the fundamental operations.

---

## 5. Time Complexity

| Operation | Time Complexity |
|---|---|
| Search | O(log n) |
| Insertion | O(log n) |
| Deletion | O(log n) |
| Minimum / Maximum | O(log n) |
| Successor / Predecessor | O(log n) |

Insertion and deletion involve searching for a node and then restoring Red-Black properties.

The number of rotations required is bounded by a constant for insertion and deletion, while recolouring may propagate upwards through the tree.

---

## 6. AVL Trees vs Red-Black Trees

Both AVL Trees and Red-Black Trees are self-balancing Binary Search Trees.

However, they maintain balance differently.

| Feature | AVL Tree | Red-Black Tree |
|---|---|---|
| Balancing mechanism | Height / Balance Factor | Node colours |
| Balance condition | Height difference at most 1 | Red-Black properties |
| Strictness | More strictly balanced | Less strictly balanced |
| Search | O(log n) | O(log n) |
| Insertion | O(log n) | O(log n) |
| Deletion | O(log n) | O(log n) |
| Rotations | May require multiple rebalancing steps | Limited number of rotations |

### Which is better?

- AVL Trees are more strictly balanced, which can make searching faster due to smaller height.
- Red-Black Trees allow more flexibility and can require fewer rotations during updates.
- Red-Black Trees are useful when insertions and deletions are frequent.

Neither is universally better. The choice depends on the application and its workload.

---

## 7. Important Observations

1. A Red-Black Tree is a self-balancing Binary Search Tree.
2. Every new node is initially inserted as RED.
3. The root is always BLACK.
4. Two consecutive RED nodes are not allowed.
5. Every root-to-NIL path has the same black height.
6. Insertion uses recolouring and rotations.
7. Deletion may create a Double Black situation.
8. The Double Black situation is resolved using the sibling and its children.
9. A Red-Black Tree can be interpreted as a 2-3-4 Tree.
10. Its maximum height is bounded by \(2\log_2(n+1)\).

## 8. Final Complexity Summary

| Tree | Search | Insertion | Deletion |
|---|---|---|---|
| BST (average) | O(log n) | O(log n) | O(log n) |
| BST (worst) | O(n) | O(n) | O(n) |
| 2-3 Tree | O(log n) | O(log n) | O(log n) |
| 2-3-4 Tree | O(log n) | O(log n) | O(log n) |
| AVL Tree | O(log n) | O(log n) | O(log n) |
| Red-Black Tree | O(log n) | O(log n) | O(log n) |
