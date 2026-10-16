# Array Manipulation Techniques & Algorithms

This module covers fundamental array manipulation techniques widely tested in competitive programming, particularly **Two Pointers**, **Sliding Window**, and **Subarray Optimization**.

---

## 1. Longest Unique Subarray (`Largest-Unique-subarray/`)

### Concept & Intuition
Given an array $A$ of size $N$, find the length of the longest contiguous subarray where all elements are distinct.
- A brute-force check examining all $O(N^2)$ subarrays takes $O(N^3)$ or $O(N^2)$ time with a hash set.
- Using the **Sliding Window / Two-Pointer** pattern reduces this to linear time $O(N)$.

### Algorithmic Mechanism
1. Maintain two pointers: `L` (window left boundary) and `R` (window right boundary), along with a frequency map / last-seen index table `last_pos`.
2. Expand `R` from $0$ to $N - 1$:
   - If $A[R]$ was previously seen at index $k \ge L$, a duplicate is inside the current window.
   - Advance `L = k + 1` to restore the unique invariant.
   - Update `last_pos[A[R]] = R`.
   - The current valid window length is $R - L + 1$.
3. Maximize over all valid window lengths:
   $$\text{MaxLen} = \max(\text{MaxLen}, \; R - L + 1)$$

### Complexity
- **Time Complexity:**
  - $O(N)$ with `std::unordered_map` or coordinate-compressed direct array.
  - $O(N \log N)$ with `std::map`.
- **Space Complexity:** $O(N)$ to store element positions in the map.

### Common Pitfalls
- Forgetting to only shift `L` **forward** (`L = max(L, last_pos[x] + 1)`). If `last_pos[x] < L`, the previous occurrence is already outside the active window and must not pull `L` backwards.
- Using 1-based indexing inconsistently between array pointers and map entries.

---

## 2. Maximum Product Subarray (`maximum-product-of-the-array/`)

### Concept & Intuition
Given an integer array $A$ containing positive numbers, negative numbers, and zeros, find the contiguous subarray that has the maximum product of its elements.
- Unlike the Maximum Sum Subarray (Kadane's algorithm), negative numbers invert signs: a very small negative product multiplied by another negative number becomes a large positive product.
- Zeros act as boundaries that reset the product.

### Two-Pass Mechanism (Prefix & Suffix Products)
1. **Zero as a delimiter**: Any subarray containing zero has product 0 (unless it's just `[0]`). Thus, zeroes split the array into non-zero segments.
2. In any non-zero segment:
   - If the count of negative numbers is **even**, the product of the entire segment is positive and optimal.
   - If the count of negative numbers is **odd**, removing either the prefix up to the first negative number OR the suffix from the last negative number leaves an even number of negatives.
3. Therefore, the maximum product subarray **must either be a prefix or a suffix** of one of the zero-delimited segments.
4. Scanning once from **left to right** (forward product) and once from **right to left** (backward product), resetting running product to 1 whenever hitting 0, is guaranteed to test all candidate prefix and suffix segments.

$$\text{Result} = \max \left( \max_{i} (\text{PrefixProduct}_i), \; \max_{i} (\text{SuffixProduct}_i) \right)$$

### Complexity
- **Time Complexity:** $O(N)$ — two linear scans.
- **Space Complexity:** $O(1)$ auxiliary memory.

### DP State Alternative
Alternatively, track both `max_ending_here` and `min_ending_here` at each index $i$:
$$\text{MaxProd}[i] = \max(A[i], \; A[i] \cdot \text{MaxProd}[i-1], \; A[i] \cdot \text{MinProd}[i-1])$$
$$\text{MinProd}[i] = \min(A[i], \; A[i] \cdot \text{MaxProd}[i-1], \; A[i] \cdot \text{MinProd}[i-1])$$
Both approaches achieve optimal $O(N)$ time and $O(1)$ space.
