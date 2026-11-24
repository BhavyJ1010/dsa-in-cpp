# Merge Sort and K-Way Merging

## 1. Merging Two Sorted Lists

Merging is the process of combining two or more sorted lists into a single sorted list.

Consider two sorted arrays:

A = [2, 8, 15]

B = [5, 9, 12, 17]

The elements are compared one by one, and the smaller element is copied into the result.

The merged array is:

C = [2, 5, 8, 9, 12, 15, 17]

### Algorithm

1. Maintain one pointer for each sorted array.
2. Compare the elements at the current positions.
3. Copy the smaller element into the result.
4. Move the pointer of the array from which the element was copied.
5. Continue until one array is exhausted.
6. Copy all remaining elements from the other array.

### Complexity

If the two arrays contain m and n elements:

T(m,n) = O(m+n)

Every element is processed exactly once.

---

## 2. Two-Way Merge Sort

Merge Sort is a Divide and Conquer sorting algorithm.

It repeatedly divides an array into two halves until individual elements remain, then merges the smaller sorted parts to produce larger sorted parts.

### Working

1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the two sorted halves.
4. Continue until the complete array is sorted.

### Example

Consider:

A = [8, 3, 7, 4, 9, 2, 6, 5]

**Division:**

    [8,3,7,4,9,2,6,5]
             /       \
        [8,3,7,4]   [9,2,6,5]
          /   \       /   \
        [8,3] [7,4] [9,2] [6,5]
         / \   / \   / \   / \
        [8][3][7][4][9][2][6][5]

**Merging:**

    [3,8] [4,7] [2,9] [5,6]
          \       /
       [3,4,7,8] [2,5,6,9]
               \ /
       [2,3,4,5,6,7,8,9]

The final array is sorted.

### Recurrence Relation

At every level:

- The problem is divided into two subproblems.
- Each subproblem has size n/2.
- Merging requires O(n) time.

Therefore:

T(n) = 2T(n/2) + n

Using the Master Theorem:

- a = 2
- b = 2
- f(n) = n

n^(log₂ 2) = n

This is Case 2.

Therefore:

T(n) = Θ(n log n)

### Complexity

| Case | Time Complexity |
|---|---|
| Best | Θ(n log n) |
| Average | Θ(n log n) |
| Worst | Θ(n log n) |

Auxiliary Space:

O(n)

Merge Sort is stable when equal elements from the left half are selected before equal elements from the right half.

The standard array implementation is not in-place because it requires additional memory for merging.

---

## 3. K-Way Merging

K-Way Merging is an extension of two-way merging.

Instead of merging two sorted lists at a time, it combines K sorted lists into one sorted list.

### Example

Consider three sorted arrays:

A = [2, 8, 15]

B = [5, 9, 12]

C = [1, 6, 17]

The merged result is:

[1, 2, 5, 6, 8, 9, 12, 15, 17]

### Working

1. Maintain a pointer to the current element of each sorted list.
2. Compare the current elements of all K lists.
3. Select the smallest element and add it to the output.
4. Move the pointer of the list from which the element was selected.
5. Repeat until all lists are exhausted.

### Approaches

**1. Simple Comparison**

At each step, compare the current elements of all K lists and select the smallest.

If the total number of elements is N:

T(N) = O(NK)

This approach is simple but becomes inefficient when K is large.

**2. Using a Min Heap**

A Min Heap can be used to efficiently find the smallest current element among the K lists.

Steps:

1. Insert the first element of every non-empty list into a Min Heap.
2. Extract the minimum element and add it to the result.
3. Insert the next element from the same list, if available.
4. Repeat until the heap becomes empty.

Each element is inserted and removed once.

Heap operations take O(log K) time.

Therefore:

T(N) = O(N log K)

Auxiliary Space:

O(K) for the heap, excluding the output array.

### Comparison

| Method | Time Complexity |
|---|---|
| Simple comparison | O(NK) |
| Min Heap | O(N log K) |

K-Way Merging is useful in external sorting, where large datasets are divided into smaller sorted files and later merged.

---

## 4. Iterative Merge Sort

Iterative Merge Sort performs sorting without recursive function calls.

Instead of repeatedly dividing the array recursively, it starts by considering individual elements as sorted lists and gradually merges them.

### Working

For an array of n elements:

1. Start with subarrays of size 1.
2. Merge adjacent subarrays to form sorted subarrays of size 2.
3. Merge adjacent subarrays of size 2 to form sorted subarrays of size 4.
4. Continue doubling the subarray size.
5. Stop when the subarray size becomes greater than or equal to n.

### Example

Consider:

A = [8, 3, 7, 4, 9, 2, 6, 5]

**Pass 1 – Subarray size 1**

    [8] [3] [7] [4] [9] [2] [6] [5]

After merging:

    [3,8] [4,7] [2,9] [5,6]

**Pass 2 – Subarray size 2**

    [3,4,7,8] [2,5,6,9]

**Pass 3 – Subarray size 4**

    [2,3,4,5,6,7,8,9]

The array is now sorted.

### Complexity

The number of passes is:

log₂ n

Each pass processes all n elements.

Therefore:

T(n) = Θ(n log n)

Auxiliary Space:

O(n)

### Advantages

- No recursion stack is required.
- Predictable number of passes.
- Useful when recursive calls are undesirable.

---

## 5. Recursive Merge Sort

Recursive Merge Sort follows the Divide and Conquer approach directly.

It repeatedly divides the array into smaller halves until each subarray contains only one element.

Then it merges the subarrays in sorted order.

### Working

1. Find the middle index.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. Merge both sorted halves.

### Recursive Structure

    MergeSort(A, low, high)
    {
        if(low < high)
        {
            mid = (low + high) / 2

            MergeSort(A, low, mid)

            MergeSort(A, mid + 1, high)

            Merge(A, low, mid, high)
        }
    }

### Complexity

The recurrence is:

T(n) = 2T(n/2) + n

Therefore:

T(n) = Θ(n log n)

Auxiliary Space:

O(n) for merging, plus O(log n) recursion stack.

The recursive version is generally easier to understand and implement, while the iterative version avoids recursive function calls.

### Iterative vs Recursive Merge Sort

| Feature | Iterative | Recursive |
|---|---|---|
| Approach | Bottom-up | Top-down |
| Function calls | No recursive calls | Recursive calls |
| Time Complexity | Θ(n log n) | Θ(n log n) |
| Auxiliary Space | O(n) | O(n) for merging, plus O(log n) recursion stack |
| Implementation | Uses increasing subarray sizes | Uses recursive division |

Both approaches produce the same sorted result and have the same asymptotic time complexity.

---

## 6. Important Points

1. Two-Way Merge combines two sorted lists.
2. K-Way Merge combines K sorted lists.
3. A Min Heap improves K-Way Merge from O(NK) to O(N log K).
4. Merge Sort uses Divide and Conquer.
5. Merge Sort has Θ(n log n) time complexity in all cases.
6. Iterative Merge Sort uses a bottom-up approach.
7. Recursive Merge Sort uses a top-down approach.
8. Standard Merge Sort requires O(n) auxiliary space.
9. Merge Sort is stable when equal elements are handled consistently during merging.