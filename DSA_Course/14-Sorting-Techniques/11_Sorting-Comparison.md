# Sorting Techniques – Comparison

Let:

- `n` = number of elements
- `k` = range of input values (or number of buckets, depending on the algorithm)
- `d` = number of digits in the maximum number

## 1. Time Complexity Comparison

| Sorting Algorithm | Best Case | Average Case | Worst Case |
|---|---:|---:|---:|
| Bubble Sort (Optimized) | O(n) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) |
| Bin Sort (Frequency Array) | O(n + k) | O(n + k) | O(n + k) |
| Bucket Sort | O(n + k)* | O(n + k)* | O(n²) |
| Radix Sort | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) |
| Shell Sort (Halving Gap) | Depends on input | Depends on input | O(n²) |

*Bucket Sort's expected linear performance assumes a reasonably uniform distribution of elements across buckets. Its actual performance depends on how elements are distributed.*

## 2. Space Complexity and Properties

| Algorithm | Auxiliary Space | Stable | In-place |
|---|---:|---|---|
| Bubble Sort | O(1) | Yes | Yes |
| Insertion Sort | O(1) | Yes | Yes |
| Selection Sort | O(1) | No | Yes |
| Quick Sort | O(log n) average, O(n) worst (recursion stack) | No | Yes* |
| Merge Sort | O(n) | Yes | No |
| Heap Sort | O(1) | No | Yes |
| Counting Sort | O(k) | No** | No |
| Bin Sort | O(k) | No | No |
| Bucket Sort | O(n + k) | Yes*** | No |
| Radix Sort | O(n + k) | Yes | No |
| Shell Sort | O(1) | No | Yes |

*Quick Sort is generally considered in-place because it partitions the array without using another array, but its recursive calls require stack space.*

**The basic frequency-based Counting Sort implementation used here is not stable. A stable version can be implemented using cumulative counts and an output array.*

***The Bucket Sort implementation uses Insertion Sort within each bucket, preserving the relative order of equal values.*

## 3. Important Observations

1. **Bubble Sort:** Simple but inefficient for large datasets. The optimized version stops early if no swaps occur.
2. **Insertion Sort:** Efficient for small or nearly sorted arrays. It is adaptive and stable.
3. **Selection Sort:** Performs fewer swaps, but always takes O(n²) time.
4. **Quick Sort:** Usually very fast in practice, but its worst case is O(n²).
5. **Merge Sort:** Guarantees O(n log n) time but requires additional memory.
6. **Heap Sort:** Guarantees O(n log n) time and uses O(1) auxiliary space.
7. **Counting Sort:** Useful when the range of integer values is not very large.
8. **Bin Sort:** Uses bins corresponding to possible integer values and is efficient when the range is limited.
9. **Bucket Sort:** Works well when input values are uniformly distributed over a known range.
10. **Radix Sort:** Sorts numbers digit by digit and uses a stable sorting method for each pass.
11. **Shell Sort:** Improves upon Insertion Sort by comparing elements at larger gaps before reducing the gap to 1.

## 4. Choosing a Sorting Algorithm

- For small or nearly sorted arrays: **Insertion Sort**
- For a simple sorting method: **Bubble Sort**
- When minimizing swaps is important: **Selection Sort**
- For fast general-purpose sorting: **Quick Sort**
- When guaranteed O(n log n) time and stability are required: **Merge Sort**
- When O(1) auxiliary space and O(n log n) worst-case time are required: **Heap Sort**
- For integers with a small value range: **Counting Sort**
- For uniformly distributed values: **Bucket Sort**
- For sorting integers digit by digit: **Radix Sort**
- For improving Insertion Sort using gaps: **Shell Sort**