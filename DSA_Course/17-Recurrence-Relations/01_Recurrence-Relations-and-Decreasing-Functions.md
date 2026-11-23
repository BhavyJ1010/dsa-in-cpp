# Recurrence Relations – Introduction and Decreasing Functions

## 1. What is a Recurrence Relation?

A recurrence relation is an equation that defines a function in terms of its values for smaller inputs.

In DSA, recurrence relations are commonly used to describe the time complexity of recursive algorithms.

Example:

\[
T(n)=T(n-1)+1
\]

This means the problem of size n is solved by:
- Solving a smaller problem of size n-1.
- Performing one additional unit of work.

A recurrence relation generally requires a base condition to determine its solution.

Example:

\[
T(1)=1
\]

## 2. Methods to Solve Recurrence Relations

Common methods include:

1. Substitution / Repeated Expansion
2. Recursion Tree Method
3. Master Theorem
4. Mathematical Induction

The appropriate method depends on the form of the recurrence.

## 3. Decreasing Functions

In decreasing-function recurrences, the input size decreases by a fixed amount in each recursive call.

General form:

\[
T(n)=T(n-1)+f(n)
\]

### Example 1: T(n) = T(n-1) + 1

Given:

\[
T(n)=T(n-1)+1
\]

Expanding:

\[
T(n)=T(n-2)+1+1
\]

\[
T(n)=T(n-3)+1+1+1
\]

After k expansions:

\[
T(n)=T(n-k)+k
\]

The recursion stops when:

\[
n-k=1
\]

Therefore:

\[
k=n-1
\]

Substituting:

\[
T(n)=T(1)+(n-1)
\]

Hence:

\[
\boxed{T(n)=\Theta(n)}
\]

### Example 2: T(n) = T(n-1) + n

Given:

\[
T(n)=T(n-1)+n
\]

Expanding:

\[
T(n)=T(n-2)+(n-1)+n
\]

\[
T(n)=T(n-3)+(n-2)+(n-1)+n
\]

Continuing:

\[
T(n)=T(1)+2+3+\cdots+n
\]

Using the sum of the first n natural numbers:

\[
1+2+\cdots+n=\frac{n(n+1)}{2}
\]

Therefore:

\[
T(n)=\Theta(n^2)
\]

### Example 3: T(n) = 2T(n-1) + 1

Given:

\[
T(n)=2T(n-1)+1
\]

Expanding:

\[
T(n)=2[2T(n-2)+1]+1
\]

\[
T(n)=4T(n-2)+2+1
\]

Expanding again:

\[
T(n)=8T(n-3)+4+2+1
\]

After k expansions:

\[
T(n)=2^kT(n-k)+(2^k-1)
\]

The recursion stops when:

\[
n-k=1
\]

Therefore:

\[
k=n-1
\]

Substituting:

\[
T(n)=2^{n-1}T(1)+(2^{n-1}-1)
\]

Hence:

\[
\boxed{T(n)=\Theta(2^n)}
\]

## 4. Observations for Decreasing Functions

| Recurrence | Time Complexity |
|---|---|
| T(n) = T(n-1) + 1 | Θ(n) |
| T(n) = T(n-1) + n | Θ(n²) |
| T(n) = 2T(n-1) + 1 | Θ(2ⁿ) |

The number of recursive calls and the work performed at each level determine the overall complexity.

## 5. Important Note About Master Theorem

The standard Master Theorem is designed for divide-and-conquer recurrences of the form:

\[
T(n)=aT(n/b)+f(n)
\]

It does not directly apply to decreasing-function recurrences such as T(n-1).

For these recurrences, repeated expansion or a recursion tree is generally used.