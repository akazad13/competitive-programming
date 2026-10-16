# Segment Tree Data Structure & Advanced Variants

A **Segment Tree** is a binary tree used for storing intervals or segments. It allows querying which of the stored segments contain a given point, or querying associative range aggregates (sum, minimum, maximum, GCD, subarray sums) in $O(\log N)$ time.

---

## 1. Standard Segment Tree (`make query update.cpp`)

### Tree Structure & Storage
- Stored as an implicit binary tree in a 1D array of size $4N$:
  - Left child of `node` is `2 * node` (or `node << 1`).
  - Right child of `node` is `2 * node + 1` (or `(node << 1) | 1`).
  - Root represents the whole range $[1, N]$ at index 1.

### Core Operations
1. **`build(node, s, e)`:**
   Recursively partitions $[s, e]$ into $[s, \text{mid}]$ and $[\text{mid} + 1, e]$ until $s == e$ (leaf node).
   $$\text{tree}[\text{node}] = f(\text{tree}[\text{left}], \; \text{tree}[\text{right}])$$
   - Time Complexity: $O(N)$
2. **`query(node, s, e, L, R)`:**
   - If current range $[s, e]$ is completely inside $[L, R]$, return $\text{tree}[\text{node}]$.
   - If current range $[s, e]$ is completely outside $[L, R]$, return identity element ($0$, $\infty$, or $-\infty$).
   - Otherwise, divide into children and combine results:
     $$\text{ans} = f(\text{query}(\text{left}), \; \text{query}(\text{right}))$$
   - Time Complexity: $O(\log N)$
3. **`update(node, s, e, idx, val)`:**
   Walk down the tree to the leaf corresponding to `idx`, update the value, and recompute parent nodes on the way back up.
   - Time Complexity: $O(\log N)$

---

## 2. Lazy Propagation (`Lazy Propagation.cpp`)

### Why Lazy Propagation?
Without lazy propagation, updating all elements in a range $[L, R]$ requires visiting every leaf in $[L, R]$, taking $O(N \log N)$ time.
**Lazy Propagation** defers updates to descendant nodes until those nodes are actually accessed by subsequent queries or updates, achieving $O(\log N)$ range updates!

### Mechanism
Each node maintains two values:
- `sum`: the aggregate range value.
- `prop` (or `lazy`): a pending increment/assignment to be pushed down to children.

1. When updating range $[L, R]$:
   - If current node range $[s, e] \subseteq [L, R]$, apply the update directly to this node's `prop` and update `sum += (e - s + 1) * val`. **Return immediately without touching children!**
   - If only partially overlapping, push pending lazy values from current node down to its two children before recursing.
2. In query operations, similarly push down pending lazy updates before querying subtrees.
- **Complexity:** $O(\log N)$ for both Range Update and Range Query.

---

## 3. 2D Segment Tree (Quadtree) (`2D segmented tree.cpp`)

### Purpose
Supports 2D spatial Range Maximum / Sum Queries over a rectangular grid $A[1 \dots N][1 \dots M]$:
$$\text{Query}(r_1, c_1, r_2, c_2) = \max_{\substack{r_1 \le i \le r_2 \\ c_1 \le j \le c_2}} A[i][j]$$

### Quadtree Splitting
Each 2D segment tree node covers a bounding box $[x_1 \dots x_2] \times [y_1 \dots y_2]$ and splits into 4 quadrants:
1. Top-Left: $[x_1 \dots \text{mid}_x] \times [y_1 \dots \text{mid}_y]$
2. Top-Right: $[x_1 \dots \text{mid}_x] \times [\text{mid}_y + 1 \dots y_2]$
3. Bottom-Left: $[\text{mid}_x + 1 \dots x_2] \times [y_1 \dots \text{mid}_y]$
4. Bottom-Right: $[\text{mid}_x + 1 \dots x_2] \times [\text{mid}_y + 1 \dots y_2]$

- **Complexity:** $O(N \cdot M)$ build time, $O(\log N \cdot \log M)$ query/update time, $O(4 \cdot N \cdot M)$ space.

---

## 4. Range Maximum Subarray Sum (`Buet segment max sum.cpp`)

### Problem (SPOJ GSS1 / GSS3)
Given an array with negative and positive values, answer queries: "What is the maximum contiguous subarray sum entirely within range $[L, R]$?" in $O(\log N)$ time with point updates.

### Node State
Each node stores four values:
```cpp
struct Node {
    ll sum;     // Total sum of elements in the range
    ll preSum;  // Maximum prefix sum starting at left boundary
    ll sufSum;  // Maximum suffix sum ending at right boundary
    ll maxSum;  // Maximum contiguous subarray sum anywhere in the range
};
```

### Merging Left and Right Children
```cpp
Node merge(Node L, Node R) {
    Node parent;
    parent.sum = L.sum + R.sum;
    parent.preSum = max(L.preSum, L.sum + R.preSum);
    parent.sufSum = max(R.sufSum, R.sum + L.sufSum);
    parent.maxSum = max({L.maxSum, R.maxSum, L.sufSum + R.preSum});
    return parent;
}
```
- **Complexity:** $O(N)$ build, $O(\log N)$ per query and point update.
