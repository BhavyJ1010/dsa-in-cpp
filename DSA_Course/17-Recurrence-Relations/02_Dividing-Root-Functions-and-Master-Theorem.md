# Dividing and Root Functions – Master Theorem

## 1. Dividing Functions

In dividing-function recurrences, the input size is reduced by a constant factor in each recursive call.

Common forms include:

\[
T(n)=T(n/2)+f(n)
\]

\[
T(n)=2T(n/2)+f(n)
\]

These recurrences commonly occur in divide-and-conquer algorithms.

For simplicity, assume n is a power of 2 and the base condition is T(1) = 1.

## 2. T(n) = T(n/2) + 1

Given:

\[
T(n)=T(n/2)+1
\]

Expanding:

\[
T(n)=T(n/4)+2
\]

\[
T(n)=T(n/8)+3
\]

After k expansions:

\[
T(n)=T(n/2^k)+k
\]

The recursion stops when:

\[
\frac{n}{2^k}=1
\]

Taking logarithms:

\[
k=\log_2 n
\]

Therefore:

\[
\boxed{T(n)=\Theta(\log n)}
\]

## 3. T(n) = T(n/2) + n

Given:

\[
T(n)=T(n/2)+n
\]

Expanding:

\[
T(n)=T(n/4)+\frac n2+n
\]

\[
T(n)=T(n/8)+\frac n4+\frac n2+n
\]

Continuing:

\[
T(n)=T(1)+\frac n{2^{k-1}}+\cdots+\frac n2+n
\]

This is a geometric series:

\[
n+\frac n2+\frac n4+\cdots
\]

Its sum is less than 2n.

Therefore:

\[
\boxed{T(n)=\Theta(n)}
\]

## 4. T(n) = 2T(n/2) + 1

Given:

\[
T(n)=2T(n/2)+1
\]

Expanding:

\[
T(n)=2[2T(n/4)+1]+1
\]

\[
T(n)=4T(n/4)+3
\]

Expanding again:

\[
T(n)=8T(n/8)+7
\]

After k expansions:

\[
T(n)=2^kT(n/2^k)+(2^k-1)
\]

At the base condition:

\[
k=\log_2 n
\]

Therefore:

\[
2^k=n
\]

Hence:

\[
T(n)=nT(1)+(n-1)
\]

\[
\boxed{T(n)=\Theta(n)}
\]

## 5. T(n) = 2T(n/2) + n

Given:

\[
T(n)=2T(n/2)+n
\]

Expanding:

\[
T(n)=4T(n/4)+2n
\]

\[
T(n)=8T(n/8)+3n
\]

After k expansions:

\[
T(n)=2^kT(n/2^k)+kn
\]

At the base condition:

\[
k=\log_2 n
\]

And:

\[
2^k=n
\]

Therefore:

\[
T(n)=nT(1)+n\log_2 n
\]

Hence:

\[
\boxed{T(n)=\Theta(n\log n)}
\]

## 6. T(n) = 2T(n/2) + n²

Given:

\[
T(n)=2T(n/2)+n^2
\]

Expanding:

\[
T(n)=2\left[2T(n/4)+(n/2)^2\right]+n^2
\]

\[
T(n)=4T(n/4)+\frac{n^2}{2}+n^2
\]

Expanding again:

\[
T(n)=8T(n/8)+\frac{n^2}{4}+\frac{n^2}{2}+n^2
\]

The non-recursive work forms a geometric series:

\[
n^2+\frac{n^2}{2}+\frac{n^2}{4}+\cdots
\]

Its sum is less than 2n².

The leaf contribution is also O(n).

Therefore:

\[
\boxed{T(n)=\Theta(n^2)}
\]

## 7. Master Theorem

The Master Theorem provides a direct way to solve recurrence relations of the form:

\[
\boxed{T(n)=aT(n/b)+f(n)}
\]

Where:

- a = Number of recursive subproblems
- b = Factor by which the input size is divided
- f(n) = Work performed outside recursive calls

First calculate:

\[
p=\log_b a
\]

Then compare f(n) with:

\[
n^p=n^{\log_b a}
\]

### Case 1: f(n) is Polynomially Smaller

If:

\[
f(n)=O(n^{p-\epsilon})
\]

for some constant ε > 0, then:

\[
\boxed{T(n)=\Theta(n^p)}
\]

### Case 2: f(n) is of the Same Order

If:

\[
f(n)=\Theta(n^p\log^k n)
\]

where k ≥ 0, then:

\[
\boxed{T(n)=\Theta(n^p\log^{k+1}n)}
\]

### Case 3: f(n) is Polynomially Larger

If:

\[
f(n)=\Omega(n^{p+\epsilon})
\]

for some constant ε > 0, and the regularity condition holds:

\[
af(n/b)\leq cf(n)
\]

for some constant c < 1 and sufficiently large n, then:

\[
\boxed{T(n)=\Theta(f(n))}
\]

## 8. Applying the Master Theorem

### Example 1

\[
T(n)=T(n/2)+1
\]

Here:

- a = 1
- b = 2
- f(n) = 1

Calculate:

\[
p=\log_2 1=0
\]

\[
n^p=1
\]

Since f(n) = Θ(1), Case 2 applies.

\[
T(n)=\Theta(\log n)
\]

### Example 2

\[
T(n)=T(n/2)+n
\]

Here:

- a = 1
- b = 2
- f(n) = n

\[
p=\log_2 1=0
\]

\[
n^p=1
\]

Since f(n) = n is polynomially larger than 1, Case 3 applies.

The regularity condition is satisfied:

\[
f(n/2)=n/2\leq cn
\]

for c = 1/2.

Therefore:

\[
T(n)=\Theta(n)
\]

### Example 3

\[
T(n)=2T(n/2)+1
\]

Here:

- a = 2
- b = 2
- f(n) = 1

\[
p=\log_2 2=1
\]

\[
n^p=n
\]

Since f(n) = 1 is polynomially smaller than n, Case 1 applies.

\[
T(n)=\Theta(n)
\]

### Example 4

\[
T(n)=2T(n/2)+n
\]

Here:

- a = 2
- b = 2
- f(n) = n

\[
p=\log_2 2=1
\]

\[
n^p=n
\]

Since f(n) = Θ(n), Case 2 applies.

\[
T(n)=\Theta(n\log n)
\]

### Example 5

\[
T(n)=2T(n/2)+n^2
\]

Here:

- a = 2
- b = 2
- f(n) = n²

\[
p=\log_2 2=1
\]

\[
n^p=n
\]

Since n² is polynomially larger than n, Case 3 applies.

The regularity condition:

\[
2f(n/2)=2(n/2)^2
\]

\[
=\frac{n^2}{2}
\]

Thus:

\[
2f(n/2)\leq \frac12 f(n)
\]

The condition is satisfied.

Therefore:

\[
T(n)=\Theta(n^2)
\]

## 9. Root-Function Recurrences

In root-function recurrences, the input size is reduced by taking its square root.

Common forms include:

\[
T(n)=T(\sqrt n)+f(n)
\]

\[
T(n)=2T(\sqrt n)+f(n)
\]

These recurrences can be solved by transforming the input using logarithms.

### Transforming a Root Recurrence

Consider:

\[
T(n)=aT(\sqrt n)+f(n)
\]

Let:

\[
m=\log_2 n
\]

Therefore:

\[
n=2^m
\]

Define:

\[
S(m)=T(2^m)
\]

Since:

\[
\sqrt n=2^{m/2}
\]

The recurrence becomes:

\[
\boxed{S(m)=aS(m/2)+f(2^m)}
\]

This is now a standard dividing-function recurrence, which can be analysed using the Master Theorem.

### Example 1: T(n) = T(√n) + 1

Given:

\[
T(n)=T(\sqrt n)+1
\]

Let:

\[
m=\log_2 n
\]

The transformed recurrence is:

\[
S(m)=S(m/2)+1
\]

Using the Master Theorem:

- a = 1
- b = 2
- f(m) = 1

\[
\log_2 1=0
\]

Therefore, Case 2 applies:

\[
S(m)=\Theta(\log m)
\]

Substituting m = log n:

\[
\boxed{T(n)=\Theta(\log\log n)}
\]

### Example 2: T(n) = 2T(√n) + 1

Given:

\[
T(n)=2T(\sqrt n)+1
\]

After transformation:

\[
S(m)=2S(m/2)+1
\]

Here:

- a = 2
- b = 2
- f(m) = 1

\[
\log_2 2=1
\]

Since f(m) is polynomially smaller than m, Case 1 applies.

\[
S(m)=\Theta(m)
\]

Substituting:

\[
\boxed{T(n)=\Theta(\log n)}
\]

### Example 3: T(n) = T(√n) + log n

Given:

\[
T(n)=T(\sqrt n)+\log_2 n
\]

Let:

\[
m=\log_2 n
\]

The recurrence becomes:

\[
S(m)=S(m/2)+m
\]

Here:

- a = 1
- b = 2
- f(m) = m

\[
\log_2 1=0
\]

Since f(m) is polynomially larger than m⁰, Case 3 applies.

\[
S(m)=\Theta(m)
\]

Therefore:

\[
\boxed{T(n)=\Theta(\log n)}
\]

### Example 4: T(n) = 2T(√n) + log n

Given:

\[
T(n)=2T(\sqrt n)+\log_2 n
\]

Let:

\[
m=\log_2 n
\]

The recurrence becomes:

\[
S(m)=2S(m/2)+m
\]

Here:

- a = 2
- b = 2
- f(m) = m

\[
\log_2 2=1
\]

Since f(m) = Θ(m), Case 2 applies.

\[
S(m)=\Theta(m\log m)
\]

Substituting:

\[
\boxed{T(n)=\Theta(\log n\log\log n)}
\]

## 10. Summary of Recurrence Relations

### Decreasing Functions

| Recurrence | Complexity |
|---|---|
| T(n) = T(n-1) + 1 | Θ(n) |
| T(n) = T(n-1) + n | Θ(n²) |
| T(n) = 2T(n-1) + 1 | Θ(2ⁿ) |

### Dividing Functions

| Recurrence | Complexity |
|---|---|
| T(n) = T(n/2) + 1 | Θ(log n) |
| T(n) = T(n/2) + n | Θ(n) |
| T(n) = 2T(n/2) + 1 | Θ(n) |
| T(n) = 2T(n/2) + n | Θ(n log n) |
| T(n) = 2T(n/2) + n² | Θ(n²) |

### Root Functions

| Recurrence | Complexity |
|---|---|
| T(n) = T(√n) + 1 | Θ(log log n) |
| T(n) = 2T(√n) + 1 | Θ(log n) |
| T(n) = T(√n) + log n | Θ(log n) |
| T(n) = 2T(√n) + log n | Θ(log n log log n) |

## 11. Important Logarithm Identities

These are useful when solving recurrence relations:

\[
\log(a^b)=b\log a
\]

\[
\log(\sqrt n)=\frac12\log n
\]

\[
\log_2 n=k \Rightarrow n=2^k
\]

\[
\log_2(\log_2 n)=\log_2\log_2 n
\]

Remember:

\[
\log\log n
\]

grows much more slowly than:

\[
\log n
\]

## 12. Limitations of Master Theorem

The standard Master Theorem cannot directly solve every recurrence.

It applies to recurrences of the form:

\[
T(n)=aT(n/b)+f(n)
\]

It does not directly apply to:
- T(n) = T(n-1) + f(n)
- T(n) = T(√n) + f(n)
- Recurrences with significantly unequal subproblem sizes, such as T(n) = T(n/3) + T(2n/3) + n.

Such recurrences require other methods or an extended theorem.

## 13. How to Approach a Recurrence Question

1. Identify the form of the recurrence.
2. Check whether the input decreases by 1, is divided by a constant, or is reduced by a root.
3. Select the appropriate solving method.
4. Expand the recurrence or transform it if required.
5. Identify the stopping condition.
6. Substitute the number of expansions.
7. Simplify the expression.
8. Write the final asymptotic complexity using Θ notation when a tight bound is established.