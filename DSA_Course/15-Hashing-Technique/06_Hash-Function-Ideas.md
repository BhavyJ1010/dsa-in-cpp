# Hash Function Ideas

A hash function converts a key into an index of a hash table.

A good hash function should be simple, fast and distribute keys uniformly.

## 1. Division Method

The key is divided by the table size, and the remainder is used as the index.

\[
h(key)=key \% m
\]

Where m is the size of the hash table.

Example:

If key = 123 and m = 10:

\[
h(123)=123 \% 10=3
\]

This is one of the simplest and most commonly used methods.

## 2. Mid-Square Method

In this method:

1. Square the given key.
2. Extract the middle digits or bits.
3. Use the extracted value as the hash index.

Example:

Key = 44

\[
44^2=1936
\]

Taking the middle two digits gives 93.

The result can be adjusted to fit the hash-table size.

## 3. Folding Method

In this method, the key is divided into smaller parts.

The parts are added together to obtain the hash value.

Example:

Key = 123456

Divide into parts:

12, 34, 56

\[
12+34+56=102
\]

The result is then mapped to a valid table index.

## 4. Multiplication Method

The key is multiplied by a constant A, where:

\[
0 < A < 1
\]

The fractional part of the result is multiplied by the table size.

\[
h(key)=\lfloor m \times (keyA \mod 1)\rfloor
\]

Where:
- m = table size
- A = constant between 0 and 1
- \(\lfloor x \rfloor\) = greatest integer less than or equal to x

## 5. Important Properties of a Good Hash Function

- It should be easy to calculate.
- It should distribute keys uniformly.
- It should minimize collisions.
- It should always produce an index within the hash-table range.

## 6. Comparison of Collision Resolution Techniques

| Technique | Method | Main Feature |
|---|---|---|
| Chaining | Linked lists at each index | Multiple keys can occupy the same index |
| Linear Probing | Checks next consecutive position | Simple, but causes primary clustering |
| Quadratic Probing | Checks quadratic increments | Reduces primary clustering |
| Double Hashing | Uses a second hash function | Generally provides better distribution |

## 7. Clustering

Clustering occurs when groups of occupied positions form in a hash table.

**Primary Clustering:** In Linear Probing, consecutive occupied positions form clusters. New collisions tend to enlarge these clusters.

**Secondary Clustering:** In Quadratic Probing, keys with the same initial hash value follow the same probing sequence.

Double Hashing reduces both forms of clustering by using a second hash function to determine the step size.