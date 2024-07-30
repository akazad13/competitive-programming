
# Different Sorting Algorithms

## Table of Contents

- [Counting Sort](#counting-sort)
- [Radix Sort](#radix-sort)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Heap Sort](#heap-sort)

### Counting Sort

#### Time Complexity:

`O(n+m)`, where n and m are the sizes of `nums[]` and `count[]` respectively.

- **Best Case**: `Ω(n+m)`.
- **Average Case**: `θ(n+m)`.
- **Worst Case**: `O(n+m)`.

#### Space Complexity:
- `O(n+m)`, where n and m are the sizes of `nums[]` and `count[]` respectively.


### Radix Sort

#### Time Complexity:

`O(d*(n+b))`, where `d` is the number of digits, `n` is the number of elements, and `b` is the base of the number system being used.

- **Best Case**: `Ω(d*(n+b))`.
- **Average Case**: `θ(d*(n+b))`.
- **Worst Case**: `O(d*(n+b))`.

#### Space Complexity:
- `O(n+b)`, where `n` is the number of elements and `b` is the base of the number system.

### Merge Sort

#### Time Complexity:

- **Best Case**: `Ω(nlogn)`, When the array is already sorted or nearly sorted.
- **Average Case**: `θ(nlogn)`, When the array is randomly ordered.
- **Worst Case**: `O(nlogn)`, When the array is sorted in reverse order.

#### Space Complexity:
- `O(n)`, Additional space is required for the temporary array used during merging.

### Quick Sort

#### Time Complexity:

- **Best Case**: `Ω(nlogn)`, when the pivot chosen at each step divides the array into roughly equal halves. The algorithm creates balanced partitions in this case, leading to efficient sorting.
- **Average Case**: `θ(nlogn)`, Quicksort's average-case performance is typically very good in practice, making it one of the fastest sorting algorithms.
- **Worst Case**: `O(n^2)`, when the pivot at each step consistently results in highly unbalanced partitions, such as when the array is already sorted and the pivot is always chosen as the smallest or largest element. Various techniques are used to mitigate the worst-case scenario, such as choosing a good pivot (e.g., median of three) and using a randomized algorithm (Randomized Quicksort) to shuffle the elements before sorting.

#### Space Complexity:
- `O(1)`, If we don't consider the recursive stack space. If we do consider the recursive stack space, then in the worst case, quicksort could use `O(n)` space.

### Heap Sort

#### Time Complexity:

- `O(nlogn)` 

#### Space Complexity:
- `O(logn)`, due to the recursive call stack. However, auxiliary space can be `O(1)` for iterative implementation.


### Summary

#### Time Complexity:

| Algorithm     | Best Case    | Average case | Worst Case   |
|---------------|--------------|--------------|--------------|
| Counting Sort | `Ω(n+m)`     | `θ(n+m)`     | `O(n+m)`     |
| Radix Sort    | `Ω(d*(n+b))` | `θ(d*(n+b))` | `O(d*(n+b))` |
| Merge Sort    | `Ω(nlogn)`   | `θ(nlogn)`   | `O(nlogn)`   |
| Quick Sort    | `Ω(nlogn)`   | `θ(nlogn)`   | `O(n^2)`     |
| Heap Sort     | `Ω(nlogn)`   | `θ(nlogn)`   | `O(nlogn)`   |

#### Space Complexity:

| Algorithm     | Complexity |
|---------------|------------|
| Counting Sort | `Ω(n+m)`   |
| Radix Sort    | `Ω(n+b)`   |
| Merge Sort    | `Ω(n)`     |
| Quick Sort    | `Ω(1)`     |
| Heap Sort     | `Ω(1)`     |
