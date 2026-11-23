# Asymptotic Notations

## 1. Comparison of Functions

In algorithm analysis, we compare functions to understand how their growth changes as the input size increases.

For example:

\[
f(n)=n^2
\]

\[
g(n)=n^3
\]

For smaller values of n, the difference may not be very significant. However, as n increases, n³ grows much faster than n².

Example:

| n | n² | n³ |
|---|---:|---:|
| 10 | 100 | 1,000 |
| 100 | 10,000 | 1,000,000 |
| 1,000 | 1,000,000 | 1,000,000,000 |

Therefore, we say:

\[
n^2 < n^3
\]

for sufficiently large n.

### Common Growth Rates

The following is the general order of growth, from slower to faster:

\[
1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n!
\]

This order helps compare the efficiency of algorithms.

For example:

- O(log n) generally grows slower than O(n).
- O(n) generally grows slower than O(n²).
- O(n²) generally grows slower than O(2ⁿ).

### Important Observation

When analysing an algorithm, we are primarily interested in its behaviour for large input sizes.

Constant factors and lower-order terms become less significant as n increases.

For example:

\[
f(n)=3n^2+5n+10
\]

The dominant term is n².

Therefore, its asymptotic growth is:

\[
\Theta(n^2)
\]

Similarly:

\[
g(n)=100n+500
\]

has asymptotic growth:

\[
\Theta(n)
\]

Even though the constants are large, they do not change the order of growth.

---

## 2. Why Asymptotic Notations?

Asymptotic notations provide a mathematical way to describe the growth rate of an algorithm as the input size approaches infinity.

They are useful because:

1. They allow comparison of algorithms independent of hardware.
2. They ignore constant factors and lower-order terms.
3. They describe the behaviour of algorithms for large inputs.
4. They provide a standard mathematical representation of time and space complexity.

Consider two algorithms:

\[
T_1(n)=5n^2+10n+20
\]

\[
T_2(n)=100n+500
\]

For small input sizes, the first algorithm may sometimes perform better.

However, as n increases, the quadratic term dominates.

Their asymptotic complexities are:

\[
T_1(n)=\Theta(n^2)
\]

\[
T_2(n)=\Theta(n)
\]

Therefore, the second algorithm scales better for sufficiently large inputs.

---

## 3. Asymptotic Notations

There are three major asymptotic notations:

1. Big O – Upper Bound
2. Big Omega – Lower Bound
3. Big Theta – Tight Bound

Two additional notations are:

4. Little o – Strict Upper Bound
5. Little omega – Strict Lower Bound

### 3.1 Big O Notation – O(g(n))

Big O represents an asymptotic upper bound on the growth of a function.

It describes a function that does not grow faster than another function, apart from a constant factor, for sufficiently large n.

Mathematical definition:

\[
f(n)=O(g(n))
\]

if there exist positive constants c and n₀ such that:

\[
0\leq f(n)\leq c\cdot g(n)
\]

for all:

\[
n\geq n_0
\]

Here:
- c = Positive constant.
- n₀ = Minimum input size from which the inequality holds.

#### Example

Prove that:

\[
f(n)=3n^2+5n+2
\]

is O(n²).

We need to establish:

\[
3n^2+5n+2\leq c n^2
\]

For n ≥ 1:

\[
5n\leq 5n^2
\]

and:

\[
2\leq 2n^2
\]

Therefore:

\[
3n^2+5n+2\leq 10n^2
\]

Choosing:

\[
c=10,\quad n_0=1
\]

Hence:

\[
\boxed{f(n)=O(n^2)}
\]

#### Important Points

- Big O gives an upper bound.
- It is commonly used to express worst-case time complexity.
- It does not necessarily represent the tightest possible bound.

For example:

\[
n=O(n^2)
\]

is mathematically correct, even though O(n) is a tighter bound.

### 3.2 Big Omega Notation – Ω(g(n))

Big Omega represents an asymptotic lower bound on the growth of a function.

It describes a function that grows at least as fast as another function, apart from a constant factor, for sufficiently large n.

Mathematical definition:

\[
f(n)=\Omega(g(n))
\]

if there exist positive constants c and n₀ such that:

\[
0\leq c\cdot g(n)\leq f(n)
\]

for all:

\[
n\geq n_0
\]

#### Example

Prove that:

\[
f(n)=3n^2+5n+2
\]

is Ω(n²).

We need:

\[
c n^2\leq 3n^2+5n+2
\]

Since:

\[
3n^2\leq 3n^2+5n+2
\]

we can choose:

\[
c=3,\quad n_0=1
\]

Therefore:

\[
\boxed{f(n)=\Omega(n^2)}
\]

#### Important Points

- Big Omega gives a lower bound.
- It describes the minimum asymptotic growth guaranteed by the function.
- It is not automatically the best-case complexity of an algorithm.

### 3.3 Big Theta Notation – Θ(g(n))

Big Theta represents a tight asymptotic bound.

It means that a function is bounded both above and below by constant multiples of another function.

Mathematical definition:

\[
f(n)=\Theta(g(n))
\]

if there exist positive constants c₁, c₂ and n₀ such that:

\[
0\leq c_1g(n)\leq f(n)\leq c_2g(n)
\]

for all:

\[
n\geq n_0
\]

#### Example

Prove that:

\[
f(n)=3n^2+5n+2
\]

is Θ(n²).

Lower bound:

\[
3n^2\leq 3n^2+5n+2
\]

Upper bound:

\[
3n^2+5n+2\leq 10n^2
\]

for n ≥ 1.

Therefore:

\[
3n^2\leq f(n)\leq 10n^2
\]

Choosing:

\[
c_1=3,\quad c_2=10,\quad n_0=1
\]

Hence:

\[
\boxed{f(n)=\Theta(n^2)}
\]

#### Important Points

- Big Theta gives both upper and lower bounds.
- It represents the tight asymptotic growth rate.
- If a function is Θ(n²), it is also O(n²) and Ω(n²).

### 3.4 Little o Notation – o(g(n))

Little o represents a strict asymptotic upper bound.

A function f(n) is o(g(n)) if it grows strictly slower than g(n).

Mathematical definition:

\[
f(n)=o(g(n))
\]

if, for every positive constant c, there exists n₀ such that:

\[
0\leq f(n)<c\cdot g(n)
\]

for all:

\[
n\geq n_0
\]

An equivalent limit-based condition, when the limit exists, is:

\[
\lim_{n\to\infty}\frac{f(n)}{g(n)}=0
\]

#### Example

\[
f(n)=n,\quad g(n)=n^2
\]

Then:

\[
\lim_{n\to\infty}\frac{n}{n^2}
=
\lim_{n\to\infty}\frac1n=0
\]

Therefore:

\[
\boxed{n=o(n^2)}
\]

### 3.5 Little omega Notation – ω(g(n))

Little omega represents a strict asymptotic lower bound.

A function f(n) is ω(g(n)) if it grows strictly faster than g(n).

Mathematical definition:

\[
f(n)=\omega(g(n))
\]

if, for every positive constant c, there exists n₀ such that:

\[
0\leq c\cdot g(n)<f(n)
\]

for all:

\[
n\geq n_0
\]

An equivalent limit-based condition, when the limit exists, is:

\[
\lim_{n\to\infty}\frac{f(n)}{g(n)}=\infty
\]

#### Example

\[
f(n)=n^2,\quad g(n)=n
\]

Then:

\[
\lim_{n\to\infty}\frac{n^2}{n}
=
\lim_{n\to\infty}n=\infty
\]

Therefore:

\[
\boxed{n^2=\omega(n)}
\]

---

## 4. Comparison of Asymptotic Notations

| Notation | Meaning | Type of Bound |
|---|---|---|
| O(g(n)) | At most | Upper bound |
| Ω(g(n)) | At least | Lower bound |
| Θ(g(n)) | Same order | Tight bound |
| o(g(n)) | Strictly slower | Strict upper bound |
| ω(g(n)) | Strictly faster | Strict lower bound |

### Relationship Between Notations

If:

\[
f(n)=\Theta(g(n))
\]

then:

\[
f(n)=O(g(n))
\]

and:

\[
f(n)=\Omega(g(n))
\]

Also:

\[
f(n)=o(g(n))\Rightarrow f(n)=O(g(n))
\]

and:

\[
f(n)=\omega(g(n))\Rightarrow f(n)=\Omega(g(n))
\]

However, the reverse implications are not necessarily true.

### Visual Understanding

- O(g(n)): f(n) stays at or below a constant multiple of g(n), eventually.
- Ω(g(n)): f(n) stays at or above a constant multiple of g(n), eventually.
- Θ(g(n)): f(n) stays between two positive constant multiples of g(n), eventually.

---

## 5. Using Asymptotic Notations

Asymptotic notations can be used to simplify expressions and compare algorithm complexities.

### Example 1

\[
f(n)=5n^2+3n+10
\]

The highest-order term is n².

Therefore:

\[
f(n)=\Theta(n^2)
\]

### Example 2

\[
f(n)=4n^3+10n^2+5n+1
\]

The highest-order term is n³.

Therefore:

\[
f(n)=\Theta(n^3)
\]

### Example 3

\[
f(n)=3n\log n+5n+10
\]

For sufficiently large n:

\[
n\log n
\]

dominates n and the constant term.

Therefore:

\[
f(n)=\Theta(n\log n)
\]

### Example 4

\[
f(n)=2^n+100n^3
\]

The exponential term eventually dominates the polynomial term.

Therefore:

\[
f(n)=\Theta(2^n)
\]

### Common Rules

1. Ignore constant coefficients.

\[
5n^2=\Theta(n^2)
\]

2. Ignore lower-order terms.

\[
n^2+n+1=\Theta(n^2)
\]

3. For a polynomial, the highest-degree term determines the asymptotic growth.

\[
3n^4+5n^2+n=\Theta(n^4)
\]

4. Logarithm bases differ only by a constant factor.

\[
\log_a n=\Theta(\log_b n)
\]

for fixed bases a, b > 1.

5. Multiplying by a positive constant does not change the asymptotic order.

\[
100n=\Theta(n)
\]

### Important Comparison of Common Functions

For sufficiently large n:

\[
1<\log n<n<n\log n<n^2<n^3<2^n<n!
\]

This is a useful general growth hierarchy.

---

## 6. Best Case and Worst Case Analysis

The time taken by an algorithm can depend on the input arrangement, even when the input size remains the same.

Therefore, algorithm analysis considers different cases.

### Best Case

The best case is the minimum time taken by an algorithm for any input of size n.

It represents the most favourable input arrangement.

### Worst Case

The worst case is the maximum time taken by an algorithm for any input of size n.

It represents the least favourable input arrangement.

### Average Case

The average case is the expected time taken over all possible inputs of size n, assuming a specified probability distribution over those inputs.

### Example: Linear Search

Consider an array:

\[
A=[10,20,30,40,50]
\]

We search for a particular element.

**Best Case:**

The element is present at the first position.

Only one comparison is required.

\[
T(n)=1
\]

Therefore:

\[
\boxed{T(n)=\Theta(1)}
\]

**Worst Case:**

The element is present at the last position or is not present in the array.

All n elements must be checked.

\[
T(n)=n
\]

Therefore:

\[
\boxed{T(n)=\Theta(n)}
\]

**Average Case:**

Assuming the element is equally likely to be at any position and is guaranteed to be present, the average number of comparisons is:

\[
T(n)=\frac{1+2+\cdots+n}{n}
\]

\[
=\frac{n(n+1)}{2n}
\]

\[
=\frac{n+1}{2}
\]

Therefore:

\[
\boxed{T(n)=\Theta(n)}
\]

### Comparison

| Case | Comparisons | Complexity |
|---|---:|---|
| Best | 1 | Θ(1) |
| Average (present element, equally likely positions) | (n+1)/2 | Θ(n) |
| Worst | n | Θ(n) |

### Example: Insertion Sort

Insertion Sort performs differently depending on the initial arrangement of elements.

**Best Case:**

The array is already sorted.

Only one comparison is needed for each element after the first, with no shifting.

\[
T(n)=\Theta(n)
\]

**Worst Case:**

The array is sorted in reverse order.

Every new element must be compared with and shifted past all previously sorted elements.

\[
T(n)=1+2+3+\cdots+(n-1)
\]

\[
T(n)=\frac{n(n-1)}{2}
\]

Therefore:

\[
T(n)=\Theta(n^2)
\]

### Summary

| Algorithm | Best Case | Worst Case |
|---|---|---|
| Linear Search | Θ(1) | Θ(n) |
| Binary Search | Θ(1) | Θ(log n) |
| Bubble Sort (optimized) | Θ(n) | Θ(n²) |
| Insertion Sort | Θ(n) | Θ(n²) |
| Selection Sort | Θ(n²) | Θ(n²) |
| Merge Sort | Θ(n log n) | Θ(n log n) |
| Quick Sort | Θ(n log n) | Θ(n²) |

---

## 7. Important Points for Revision

1. Asymptotic analysis studies the growth of functions for large input sizes.
2. Big O represents an upper bound.
3. Big Omega represents a lower bound.
4. Big Theta represents a tight bound.
5. Little o represents a strict upper bound.
6. Little omega represents a strict lower bound.
7. Constants and lower-order terms are ignored when determining asymptotic growth.
8. Best case represents minimum running time for inputs of size n.
9. Worst case represents maximum running time for inputs of size n.
10. Average case depends on the assumed probability distribution of inputs.

### Important Distinction

Big O and Big Omega are mathematical bounds, not synonyms for worst-case and best-case analysis.

For example, an algorithm's worst-case running time can itself be expressed using Θ, O or Ω, depending on the bound being stated.

When a tight bound is known, Θ is the most precise description of the growth rate.