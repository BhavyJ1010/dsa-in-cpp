# Hashing – Fundamentals

## 1. Introduction

Hashing is a technique used to store and retrieve data efficiently.

A hash function converts a key into an index of a hash table, where the corresponding value is stored.

\[
h(key) = index
\]

A hash table is an array in which data is stored at positions calculated using a hash function.

Example:

If the hash function is:

\[
h(key) = key \% 10
\]

Then:

- h(16) = 6
- h(25) = 5
- h(39) = 9
- h(122) = 2

The keys are stored at their calculated indices.

## 2. Hash Function

A hash function maps a key to a valid index in the hash table.

A good hash function should:
- Be easy and fast to calculate.
- Distribute keys uniformly across the table.
- Minimize collisions.

## 3. Collision

A collision occurs when two or more keys produce the same hash-table index.

Example:

Using h(key) = key % 10:

- h(12) = 2
- h(22) = 2
- h(42) = 2

All three keys map to index 2, resulting in a collision.

Collision resolution techniques include:

1. Chaining
2. Open Addressing:
   - Linear Probing
   - Quadratic Probing
   - Double Hashing

## 4. Chaining

In chaining, each index of the hash table stores a pointer to a linked list.

When multiple keys map to the same index, they are stored in that index's linked list.

Advantages:
- Multiple keys can be stored at the same index.
- The table can store more elements than its number of indices.

Disadvantage:
- Additional memory is required for linked-list pointers and nodes.

## 5. Open Addressing

In open addressing, all elements are stored directly inside the hash table.

When a collision occurs, another empty position is searched using a probing technique.

Types:

- Linear Probing: Checks consecutive positions.
- Quadratic Probing: Checks positions using quadratic increments.
- Double Hashing: Uses a second hash function to calculate the probing interval.

## 6. Load Factor

Load factor indicates how full a hash table is.

\[
\alpha = \frac{n}{m}
\]

Where:
- n = number of stored elements
- m = size of the hash table

A higher load factor generally increases the possibility of collisions.

## 7. Time Complexity

| Operation | Average Case | Worst Case |
|---|---|---|
| Search | O(1) | O(n) |
| Insertion | O(1) | O(n) |
| Deletion | O(1) | O(n) |

Average-case performance assumes a good hash function and a controlled load factor. Worst-case performance occurs when many keys collide.
