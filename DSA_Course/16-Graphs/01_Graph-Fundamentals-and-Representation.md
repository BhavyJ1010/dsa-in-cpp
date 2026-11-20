# Graphs – Fundamentals

## 1. Introduction

A graph is a non-linear data structure consisting of a set of vertices and a set of edges connecting these vertices.

\[
G=(V,E)
\]

Where:
- V = Set of vertices (nodes)
- E = Set of edges (connections between vertices)

Example:

If:

\[
V=\{0,1,2,3\}
\]

\[
E=\{(0,1),(0,2),(1,2),(2,3)\}
\]

Then the graph contains four vertices and four edges.

## 2. Types of Graphs

### Undirected Graph

In an undirected graph, edges do not have a direction.

If vertex A is connected to vertex B, then B is also connected to A.

### Directed Graph (Digraph)

In a directed graph, edges have a direction.

An edge from A to B does not necessarily mean that an edge exists from B to A.

### Weighted Graph

A weighted graph assigns a weight or cost to each edge.

Weights may represent distance, time, cost, etc.

### Unweighted Graph

An unweighted graph has no associated weights on its edges.

## 3. Basic Terminology

- **Vertex:** A node in a graph.
- **Edge:** A connection between two vertices.
- **Adjacent Vertices:** Two vertices connected by an edge.
- **Degree:** Number of edges incident on a vertex in an undirected graph.
- **In-degree:** Number of incoming edges to a vertex in a directed graph.
- **Out-degree:** Number of outgoing edges from a vertex in a directed graph.
- **Path:** A sequence of vertices connected by edges.
- **Cycle:** A path that starts and ends at the same vertex.
- **Connected Graph:** An undirected graph in which a path exists between every pair of vertices.
- **Connected Component:** A maximal connected part of an undirected graph.

For an undirected graph:

\[
\sum Degree(v)=2|E|
\]

For a directed graph:

\[
\sum InDegree(v)=\sum OutDegree(v)=|E|
\]

## 4. Graph Representation

Graphs are commonly represented using:

1. Adjacency Matrix
2. Adjacency List

### Adjacency Matrix

An adjacency matrix is a 2D array of size V × V.

For an unweighted graph:

\[
A[i][j]=
\begin{cases}
1 & \text{if an edge exists from i to j}\\
0 & \text{otherwise}
\end{cases}
\]

For an undirected graph, the matrix is symmetric:

\[
A[i][j]=A[j][i]
\]

Space complexity: O(V²).

Checking whether an edge exists takes O(1) time.

### Adjacency List

An adjacency list stores the neighbours of each vertex.

It is generally implemented using an array of linked lists or a collection of lists.

Space complexity: O(V + E).

It is more space-efficient for sparse graphs.

## 5. Graph Traversal

Graph traversal means visiting the vertices of a graph systematically.

Two important traversal techniques are:

- Breadth First Search (BFS)
- Depth First Search (DFS)

### Breadth First Search (BFS)

BFS explores a graph level by level.

It uses a Queue (FIFO).

Steps:
1. Mark the starting vertex as visited.
2. Insert it into the queue.
3. Remove a vertex from the queue.
4. Visit all its unvisited adjacent vertices.
5. Mark them visited and insert them into the queue.
6. Repeat until the queue becomes empty.

Time complexity:
- Adjacency Matrix: O(V²)
- Adjacency List: O(V + E)

### Depth First Search (DFS)

DFS explores as far as possible along a path before backtracking.

It can be implemented using recursion (call stack) or an explicit stack.

Steps:
1. Visit the starting vertex.
2. Mark it as visited.
3. Visit an unvisited adjacent vertex recursively.
4. Continue until no unvisited adjacent vertex remains.
5. Backtrack and explore other unvisited adjacent vertices.

Time complexity:
- Adjacency Matrix: O(V²)
- Adjacency List: O(V + E)

## 6. Applications of BFS and DFS

**BFS:**
- Finding the shortest path in an unweighted graph.
- Level-order traversal.
- Finding connected components.
- Checking whether a graph is bipartite.

**DFS:**
- Cycle detection.
- Finding connected components.
- Topological sorting.
- Path finding.
- Exploring maze-like structures.

## 7. Disjoint Sets

A Disjoint Set is a data structure that maintains a collection of non-overlapping sets.

Each element belongs to exactly one set.

Two important operations are:

- **Find:** Determines the representative (root) of the set containing an element.
- **Union:** Combines the sets containing two elements.

Disjoint Sets are also called Union-Find.

### Union by Rank

The root of the smaller-rank tree is attached to the root of the larger-rank tree.

If both trees have equal rank, one root becomes the parent and its rank is increased.

### Path Compression

During the Find operation, each visited node is directly connected to the root.

This reduces the height of the tree and makes future operations faster.

With path compression and union by rank, the amortized time per operation is nearly constant:

\[
O(\alpha(n))
\]

Here, \(\alpha(n)\) is the inverse Ackermann function, which grows extremely slowly.