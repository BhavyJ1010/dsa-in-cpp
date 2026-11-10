
# Sorting Criteria and Analysis

## 1. What is Sorting?

Sorting is the process of arranging data elements in a particular order, usually ascending or descending.

Example:

Original array:
`[40, 10, 30, 20, 50]`

Ascending order:
`[10, 20, 30, 40, 50]`

Descending order:
`[50, 40, 30, 20, 10]`

Sorting is an important operation because ordered data makes searching, processing and analysing information easier.

## 2. Types of Sorting

### 2.1 Internal Sorting

Internal sorting is performed when the entire data to be sorted fits into main memory (RAM).

Examples:
- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Merge Sort
- Heap Sort

### 2.2 External Sorting

External sorting is used when the data is too large to fit entirely into main memory.

Data is processed in smaller portions, often using secondary storage such as a hard disk or SSD.

**Example:** Sorting a file containing several gigabytes of records when available RAM is insufficient to hold the entire file.

External Merge Sort is a common example.

## 3. Important Criteria for Analysing Sorting Algorithms

Sorting algorithms can be compared using several properties.

### 3.1 Time Complexity

Time complexity describes how the running time of an algorithm grows with the size of the input.

The commonly analysed cases are:

**Best Case:**

The minimum time taken by an algorithm for an input of size n.

**Average Case:**

The expected time taken over possible inputs of size n, according to an assumed input distribution.

**Worst Case:**

The maximum time taken by an algorithm for an input of size n.

For example, in Bubble Sort:

- Best case: O(n), when the optimized algorithm receives an already sorted array.
- Average case: O(n²).
- Worst case: O(n²), when the array is reverse sorted.

### 3.2 Space Complexity

Space complexity describes the additional memory required by an algorithm as the input size grows.

For sorting algorithms, we often distinguish between:

- Input space: Memory occupied by the original data.
- Auxiliary space: Extra memory used by the algorithm.

An in-place sorting algorithm generally requires only a constant amount of auxiliary memory, i.e. O(1).

### 3.3 Stability

A sorting algorithm is **stable** if equal elements retain their original relative order after sorting.

Consider records containing a name and marks:

Original order:

| Name | Marks |
|---|---:|
| A | 80 |
| B | 70 |
| C | 80 |

After stable sorting by marks in ascending order:

| Name | Marks |
|---|---:|
| B | 70 |
| A | 80 |
| C | 80 |

A and C both have 80 marks. Since A appeared before C originally, A must remain before C.

If their relative order changes, the sorting algorithm is unstable.

### 3.4 Adaptiveness

An adaptive sorting algorithm takes advantage of existing order in the input.

If the input is already sorted or nearly sorted, an adaptive algorithm may perform less work.

For example:
- Optimized Bubble Sort can finish an already sorted array in O(n).
- Insertion Sort also performs well on already sorted or nearly sorted arrays.

An algorithm that performs essentially the same work regardless of existing order is considered non-adaptive in that context.

### 3.5 In-Place Sorting

An in-place sorting algorithm rearranges elements within the original array and uses only a small, constant amount of additional memory.

Examples:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Heap Sort

Merge Sort generally requires O(n) auxiliary space for its standard array implementation.

### 3.6 Comparison-Based Sorting

Comparison-based sorting determines the order of elements by comparing pairs of values.

Examples:
- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Merge Sort
- Heap Sort
- Shell Sort

For general comparison-based sorting, the worst-case lower bound is Ω(n log n).

This means no general comparison-based sorting algorithm can guarantee better than Ω(n log n) comparisons in the worst case.

Non-comparison-based algorithms, such as Counting Sort and Radix Sort, can achieve linear-time performance under suitable assumptions about the input.

## 4. Classification of Sorting Algorithms

### Comparison-Based Sorting

These algorithms determine order through comparisons between elements.

Examples:
- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Merge Sort
- Heap Sort
- Shell Sort

### Non-Comparison-Based Sorting

These algorithms use properties of the input values instead of relying exclusively on pairwise comparisons.

Examples:
- Counting Sort
- Bucket Sort
- Radix Sort

Their performance depends on assumptions such as the value range, distribution of data or number of digits.

## 5. General Comparison of Sorting Algorithms

The following table gives the standard complexities for commonly covered algorithms.

| Algorithm | Best Case | Average Case | Worst Case | Auxiliary Space |
|---|---:|---:|---:|---:|
| Bubble Sort (optimized) | O(n) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) average recursion |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(n + k) |
| Radix Sort | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) |

Here:
- n = Number of elements.
- k = Relevant value range or digit base, depending on the algorithm.
- d = Number of digits or passes in Radix Sort.

These are standard bounds under the usual implementations and assumptions. Quick Sort's auxiliary space depends on recursion depth and can reach O(n) in the worst case.

## 6. Important Observations

1. A sorting algorithm should not be judged only by its time complexity.
2. Stability matters when sorting records using multiple keys.
3. In-place algorithms are useful when additional memory is limited.
4. Adaptive algorithms can be particularly efficient for nearly sorted data.
5. Non-comparison-based algorithms can outperform comparison-based sorting when their input assumptions are satisfied.
6. The choice of sorting algorithm depends on input size, data distribution, memory availability and required properties.

## 7. Summary

The important criteria for analysing sorting algorithms are:

- Time Complexity
- Space Complexity
- Stability
- Adaptiveness
- In-place or Out-of-place operation
- Comparison-based or Non-comparison-based approach

These criteria will be used to analyse and compare the sorting algorithms covered in this section.
