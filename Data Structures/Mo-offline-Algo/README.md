# Mo's Algorithm (Sqrt Decomposition for Offline Range Queries)

**Mo's Algorithm** is an offline algorithm that answers $Q$ range queries $[L, R]$ on a static array in $O((N + Q) \sqrt{N})$ time, provided adding or removing an element from the query range takes $O(1)$ time.

---

## 1. Core Idea & Sorting Order

If queries are answered naively, moving pointers between arbitrary $[L_i, R_i]$ intervals takes $O(N)$ per query, resulting in $O(Q \cdot N)$ total time.
Mo's algorithm sorts the queries in a specific order so that the total movement of the two pointers across all $Q$ queries is bounded by $O((N + Q) \sqrt{N})$.

### Block Partitioning
1. Divide the array of size $N$ into blocks of size $B = \lceil \sqrt{N} \rceil$.
2. Each query $[L, R]$ belongs to block $\lfloor L / B \rfloor$.
3. **Sort Criteria:**
   ```cpp
   bool compare(Query a, Query b) {
       int block_a = a.L / B;
       int block_b = b.L / B;
       if (block_a != block_b)
           return block_a < block_b;
       return (block_a & 1) ? a.R < b.R : a.R > b.R; // Alternating (snake) sort
   }
   ```

---

## 2. Complexity Analysis & Proof

Let current window pointers be `cur_L` and `cur_R`:
- **Left Pointer Movements:**
  - Between queries within the same block, $L$ moves at most $B = \sqrt{N}$ steps. For $Q$ queries: $O(Q \sqrt{N})$.
  - When changing blocks: at most $O(\sqrt{N})$ steps. Total across $N / B$ blocks: $O(N)$.
- **Right Pointer Movements:**
  - Within each block, $R$ increases monotonically from $0$ to $N$, traversing at most $N$ steps per block.
  - With $N / B = \sqrt{N}$ blocks, total $R$ movement across all blocks is $\sqrt{N} \cdot N = O(N \sqrt{N})$.
- **Total Time Complexity:**
  $$O(Q \sqrt{N} + N \sqrt{N}) = O((N + Q) \sqrt{N})$$

---

## 3. Operations Required

To apply Mo's Algorithm, the problem must support two $O(1)$ functions:
```cpp
void add(int index);    // Expand window to include index
void remove(int index); // Contract window to exclude index
```
For example, for **Number of Distinct Elements in Range (SPOJ DQUERY)**:
```cpp
void add(int idx) {
    freq[arr[idx]]++;
    if (freq[arr[idx]] == 1) distinct_count++;
}
void remove(int idx) {
    freq[arr[idx]]--;
    if (freq[arr[idx]] == 0) distinct_count--;
}
```
