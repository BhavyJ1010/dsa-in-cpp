# Divide and Conquer

## 1. Algorithm Strategies

An algorithm strategy is a general approach used to solve a problem.

Some common algorithm design strategies are:

1. **Brute Force** – Trying all possible solutions.
2. **Divide and Conquer** – Dividing a problem into smaller subproblems.
3. **Greedy Method** – Making the best local choice at each step.
4. **Dynamic Programming** – Solving overlapping subproblems and storing their results.
5. **Backtracking** – Exploring possible solutions and abandoning invalid paths.

## 2. Divide and Conquer

Divide and Conquer is an algorithm design technique in which a problem is divided into smaller subproblems of the same type.

The subproblems are solved recursively, and their results are combined to obtain the final solution.

### Three Main Steps

1. **Divide:** Break the original problem into smaller subproblems.
2. **Conquer:** Solve the subproblems recursively. If a subproblem is sufficiently small, solve it directly.
3. **Combine:** Combine the solutions of the subproblems to obtain the final result.

### General Structure

    DivideAndConquer(problem)
    {
        if problem is small:
            solve directly
            return

        divide problem into subproblems

        solve each subproblem recursively

        combine their results
    }

### Examples

- Binary Search
- Merge Sort
- Quick Sort
- Strassen's Matrix Multiplication

### Advantages

- Breaks complex problems into manageable subproblems.
- Often produces efficient algorithms.
- Supports recursive problem solving.
- Can allow parallel execution of independent subproblems.

### Disadvantages

- Recursive calls introduce function-call overhead.
- Additional memory may be required.
- Combining the results can sometimes be expensive.

---

## 3. Binary Search Using Divide and Conquer

Binary Search is an efficient searching algorithm used on a **sorted array**.

Instead of checking every element, it repeatedly divides the search interval into two halves.

### Working

1. Find the middle element of the current search interval.
2. If the middle element is the required element, return its index.
3. If the required element is smaller, search the left half.
4. If it is larger, search the right half.
5. Repeat until the element is found or the search interval becomes empty.

### Example

Consider the sorted array:

A = [10, 20, 30, 40, 50, 60, 70]

Search for:

key = 60

Initially:

- low = 0
- high = 6

Middle index:

mid = (low + high) / 2 = 3

A[3] = 40

Since 60 > 40, search the right half.

Now:

- low = 4
- high = 6
- mid = 5

A[5] = 60

The element is found at index 5.

### Iterative Binary Search

    int BinarySearch(int A[], int n, int key)
    {
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(A[mid] == key)
                return mid;

            else if(key < A[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        return -1;
    }

### Recursive Binary Search

    int BinarySearch(int A[], int low, int high, int key)
    {
        if(low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if(A[mid] == key)
            return mid;

        else if(key < A[mid])
            return BinarySearch(A, low, mid - 1, key);

        else
            return BinarySearch(A, mid + 1, high, key);
    }

### Complexity Analysis

At every step, the search interval is reduced to half.

The recurrence relation is:

T(n) = T(n/2) + 1

Using the Master Theorem:

- a = 1
- b = 2
- f(n) = 1

Therefore:

T(n) = Θ(log n)

| Case | Complexity |
|---|---|
| Best | Θ(1) |
| Average | Θ(log n) |
| Worst | Θ(log n) |

**Space Complexity:**

- Iterative Binary Search: O(1)
- Recursive Binary Search: O(log n), due to the recursion stack.

### Important Conditions

- The array must be sorted.
- The middle index should be calculated using `low + (high - low) / 2` to avoid possible integer overflow.
- Binary Search is not directly suitable for an ordinary unsorted array.

---

## 4. Divide and Conquer – Recurrence Relations

The time complexity of Divide and Conquer algorithms can generally be represented as:

T(n) = aT(n/b) + f(n)

Where:

- a = Number of subproblems.
- n/b = Size of each subproblem.
- f(n) = Work required to divide the problem and combine the results.

### Examples

**Binary Search**

T(n) = T(n/2) + 1

T(n) = Θ(log n)

**Merge Sort**

T(n) = 2T(n/2) + n

T(n) = Θ(n log n)

**Strassen's Matrix Multiplication**

T(n) = 7T(n/2) + n²

T(n) = Θ(n^(log₂ 7))

Since:

log₂ 7 ≈ 2.807

Its complexity is approximately:

O(n²·⁸⁰⁷)

---

## 5. Summary

| Algorithm | Divide | Combine | Time Complexity |
|---|---|---|---|
| Binary Search | Search interval into two halves | No significant combining | Θ(log n) |
| Merge Sort | Array into two halves | Merge sorted halves | Θ(n log n) |
| Strassen's Algorithm | Matrices into four submatrices | Combine seven products | Θ(n²·⁸⁰⁷) |

Divide and Conquer is especially useful when a problem can be divided into smaller independent subproblems and their solutions can be combined efficiently.