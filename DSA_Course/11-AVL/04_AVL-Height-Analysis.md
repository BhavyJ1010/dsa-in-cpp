# AVL Trees — Height Analysis

## 1. Why analyse AVL height?

A Binary Search Tree (BST) can become skewed. If keys are inserted in sorted order, its height can become \(n-1\) when height is measured in edges, causing search, insertion and deletion to take \(O(n)\) time.

An AVL tree maintains a balance factor of \(-1\), \(0\), or \(+1\) at every node. This restriction limits how quickly the height can grow as the number of nodes increases.

Throughout this analysis, use the following height convention:

- Height of an empty tree: \(h=0\).
- Height of a leaf: \(h=1\).
- Height of a non-empty tree: \(1+\max(\text{left height},\text{right height})\).

## 2. Minimum number of nodes for a given height

Let \(N(h)\) denote the **minimum number of nodes an AVL tree of height \(h\) can contain**.

To obtain the minimum number of nodes while maintaining height \(h\), one subtree must have height \(h-1\). The other can have height \(h-2\), because the heights of the two subtrees of an AVL node can differ by at most one.

Therefore, the smallest possible tree of height \(h\) consists of:

1. One root node.
2. A smallest AVL subtree of height \(h-1\).
3. A smallest AVL subtree of height \(h-2\).

This gives the recurrence

\[
N(h)=1+N(h-1)+N(h-2)
\]

for \(h\geq 3\).

### Base cases

Using our height convention:

\[
N(0)=0
\]

\[
N(1)=1
\]

\[
N(2)=2
\]

For height 2, a root and one child are sufficient.

### Calculate the first few values

| Height \(h\) | Calculation | Minimum nodes \(N(h)\) |
|---:|---|---:|
| 0 | Empty tree | 0 |
| 1 | One leaf | 1 |
| 2 | One root and one child | 2 |
| 3 | \(1+N(2)+N(1)\) | 4 |
| 4 | \(1+N(3)+N(2)\) | 7 |
| 5 | \(1+N(4)+N(3)\) | 12 |
| 6 | \(1+N(5)+N(4)\) | 20 |
| 7 | \(1+N(6)+N(5)\) | 33 |

The minimum-node sequence is:

\[
0,\ 1,\ 2,\ 4,\ 7,\ 12,\ 20,\ 33,\ldots
\]

The number of nodes grows rapidly as the height increases. Thus, an AVL tree cannot become arbitrarily tall while containing relatively few nodes.

## 3. Connection with the Fibonacci sequence

The Fibonacci sequence is defined by

\[
F_0=0,\quad F_1=1
\]

and

\[
F_k=F_{k-1}+F_{k-2}
\]

Compare this with the AVL recurrence:

\[
N(h)=1+N(h-1)+N(h-2)
\]

Add one to both sides:

\[
N(h)+1
= \bigl(N(h-1)+1\bigr)
+ \bigl(N(h-2)+1\bigr)
\]

Define \(M(h)=N(h)+1\). Then

\[
M(h)=M(h-1)+M(h-2)
\]

The base cases are \(M(0)=1\) and \(M(1)=2\). These are \(F_2\) and \(F_3\), respectively.

Consequently,

\[
\boxed{N(h)=F_{h+2}-1}
\]

This formula connects the minimum number of nodes in an AVL tree directly to Fibonacci numbers.

For example, when \(h=5\):

\[
N(5)=F_7-1=13-1=12
\]

which agrees with the recurrence calculation.

## 4. Deriving the logarithmic height bound

The Fibonacci sequence grows exponentially. By Binet's formula, its dominant growth is proportional to

\[
F_k \propto \varphi^k
\]

where

\[
\varphi=\frac{1+\sqrt{5}}{2}\approx 1.618
\]

is the golden ratio.

Since an AVL tree of height \(h\) must contain at least \(N(h)\) nodes,

\[
n\geq N(h)=F_{h+2}-1
\]

Rearranging the Fibonacci growth relationship gives a logarithmic bound on \(h\). In asymptotic terms,

\[
\boxed{h=O(\log n)}
\]

A commonly quoted approximate upper bound under this height convention is

\[
h\lesssim 1.4405\log_2(n+2)-0.328
\]

The important conclusion is not the exact constant; it is that the height increases logarithmically rather than linearly with the number of nodes.

## 5. Time complexity of AVL operations

Because the height is \(O(\log n)\), a search follows at most a logarithmic number of levels.

Insertion follows one root-to-leaf path, inserts the node, and updates heights while returning through the recursive calls. Any necessary rotations take constant time at each affected node.

Deletion similarly follows a path to locate the key, performs the ordinary BST deletion, and updates heights and balances on the way back up. Rebalancing may be required at multiple ancestors.

| Operation | Worst-case time |
|---|---|
| Search | \(O(\log n)\) |
| Insertion | \(O(\log n)\) |
| Deletion | \(O(\log n)\) |
| Single rotation | \(O(1)\) |
| Double rotation | \(O(1)\) |

Storing a height in every node requires \(O(n)\) total additional space across the tree. Recursive operations also use \(O(\log n)\) call-stack space on a balanced AVL tree.

## 6. AVL tree versus an ordinary BST

| Property | Ordinary BST | AVL tree |
|---|---|---|
| Balance enforced? | No | Yes |
| Worst-case height | \(O(n)\) | \(O(\log n)\) |
| Worst-case search | \(O(n)\) | \(O(\log n)\) |
| Insertion/deletion | No balancing required | May require rotations |
| Per-node metadata | Not necessarily required | Height or equivalent balance information |

An ordinary BST can be efficient when its shape is favourable, but it offers no logarithmic worst-case height guarantee. An AVL tree pays the cost of maintaining balance to provide that guarantee.

## 7. Exam-ready points

1. **AVL condition:** For every node, the absolute value of its balance factor is at most one.
2. **Balance factor:** Height of left subtree minus height of right subtree.
3. **Minimum-node recurrence:** \(N(h)=1+N(h-1)+N(h-2)\).
4. **Fibonacci relation:** \(N(h)=F_{h+2}-1\), using \(N(0)=0\) and \(N(1)=1\).
5. **Height result:** \(h=O(\log n)\).
6. **Operation complexity:** Search, insertion and deletion are \(O(\log n)\) in the worst case.
7. **Rotation complexity:** Each single or double rotation takes \(O(1)\) time.
8. **Deletion distinction:** Rebalancing after deletion uses the balance factors of the node and its heavy child, not just the deleted key.
