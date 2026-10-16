# Competitive Programming

A comprehensive repository of competitive programming templates, standard algorithms, data structures, and solutions to 560+ problems across various online judges (UVA, LightOJ, Spoj, LeetCode, CodeChef, and more).

---

## Contest Mental Checklist
Before submitting a solution:
1. **Sub-problem**: Can I solve the simplified / sub-problem first?
2. **Edge Cases**: Did I check bounds ($N = 0$, $N = 1$, negative numbers, overflow with $10^{18}$)?
3. **Data Types**: Are variables `long long int` where multiplication or sum can overflow 32-bit signed int?
4. **Memory & Reset**: Are global arrays, vectors, and DP tables cleared (`memset` / `.clear()`) for **each test case**?
5. **Time & Space Complexity**: Will this pass within the 1.0s - 2.0s time limit ($~10^8$ operations)?
6. **Problem Understanding**: Did I re-read the problem carefully, especially 1-based vs 0-based indexing?

---

## Repository Structure

```
competitive-programming/
├── Algorithms/              # Algorithmic paradigms and standard templates
├── Data Structures/         # Core & advanced data structures (Trees, Sqrt decomp, etc.)
├── Math/                    # Number theory, modular arithmetic, BigInt
├── Online Judges/           # 560+ Accepted solutions categorized by judge
├── Starting Template.cpp    # Production C++ template with fast I/O & math helpers
├── stl.txt                  # STL quick reference & useful competitive snippets
└── .gitignore               # Clean gitignore excluding binaries & object files
```

---

## 1. Algorithms (`Algorithms/`)

| Domain | Directory | Highlights |
|---|---|---|
| **Array Manipulation** | [`Algorithms/Array-Manipulation/`](Algorithms/Array-Manipulation/) | Longest Unique Subarray (sliding window), Maximum Product Subarray. |
| **Backtracking** | [`Algorithms/Backtracking/`](Algorithms/Backtracking/) | M-Coloring Graph Problem, N-Queens Problem. |
| **Dynamic Programming** | [`Algorithms/Dynamic-Programming/`](Algorithms/Dynamic-Programming/) | 0-1 Knapsack, Coin Change, Digit DP, Inclusion-Exclusion, 1D & 2D Kadane, $n\text{C}r$, Catalan BSTs, TSP with Bitmask. |
| **Computational Geometry**| [`Algorithms/Geometry/`](Algorithms/Geometry/) | Shoelace Polygon Area, Line Segment Intersection test, Closest Pair of Points (Sweep-line). |
| **Graph Theory** | [`Algorithms/Graph-Theory/`](Algorithms/Graph-Theory/) | BFS/DFS, 0-1 BFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Kruskal MST, Prim MST, DSU, Articulation Points & Bridges, Kosaraju & Tarjan SCC, 2-SAT, Dinic & Edmonds-Karp Max Flow, Heavy-Light Decomposition (HLD), Stable Marriage. |
| **Sorting** | [`Algorithms/Sorting/`](Algorithms/Sorting/) | Counting Sort, Radix Sort, Merge Sort, Quick Sort, Heap Sort (with sample I/O). |
| **String Processing** | [`Algorithms/String-Processing/`](Algorithms/String-Processing/) | KMP Algorithm, Z-Algorithm, Rabin-Karp Hash, Trie (Array & Pointer), Longest Common Subsequence (LCS), Palindromes, Smallest Cyclic Rotation. |

---

## 2. Data Structures (`Data Structures/`)

| Data Structure | Implementation | Details |
|---|---|---|
| **AVL Tree** | `AVL-tree/AVL-tree-main/` | Self-balancing binary search tree with rotations. |
| **Order-Statistic Tree** | `AVL-tree/AVL-tree-to-find-nth-min/` | Augmented AVL tree to find $k$-th minimum element in $O(\log n)$. |
| **Segment Tree (Point Update)** | `Segment-Tree/make query update.cpp` | Range Maximum Query with single-element updates. |
| **Segment Tree (Lazy Propagation)** | `Segment-Tree/Lazy Propagation.cpp` | Range Sum Query with range updates in $O(\log n)$. |
| **2D Segment Tree (Quadtree)** | `Segment-Tree/2D segmented tree.cpp` | 2D matrix range maximum queries. |
| **Segment Tree Max Subarray Sum** | `Segment-Tree/Buet segment max sum.cpp` | Range maximum contiguous subarray sum (GSS1/3). |
| **Matrix Exponentiation** | `Matrix-expo/` | General $K \times K$ and memory-efficient $2 \times 2$ fast power. |
| **Mo's Algorithm** | `Mo-offline-Algo/Mo.cpp` | Square Root Decomposition for offline range queries. |
| **Inversion Count** | `Merge-Sort/inversion_count_merge_sort.cpp` | $O(n \log n)$ inversion counting via merge sort. |
| **Cycle Detection / Min Swaps** | `minswap.cpp` | Minimum element swaps to sort an array via permutation cycles. |

---

## 3. Math & Number Theory (`Math/`)

| Topic | Directory | Key Algorithms |
|---|---|---|
| **Big Number Arithmetic** | [`Math/Big-Number-Arithemetic/`](Math/Big-Number-Arithemetic/) | Arbitrary-precision BigInt addition, subtraction, division by 2, and multiplication. |
| **Number Theory** | [`Math/Number-Theory/`](Math/Number-Theory/) | Sieve of Eratosthenes, Bitwise Sieve, Segmented Sieve, Iterative & Recursive GCD, Extended Euclidean Algorithm, Modular Inverse, Modular Exponentiation, Binary Multiplication (`mulmod`), Miller-Rabin Primality Test, Euler's Totient $\phi$, Divisor Counting $d(n)$, Legendre's Factorial Formula, Lucas' Theorem. |

---

## 4. Online Judges Solutions (`Online Judges/`)

Collection of accepted submissions:

| Judge | Platform | Solved Problems |
|:---|:---|:---:|
| **UVA Online Judge** | [Online Judges/UVA/](Online%20Judges/UVA/) | 274 |
| **LightOJ** | [Online Judges/LightOJ/](Online%20Judges/LightOJ/) | 229 |
| **Toph** | [Online Judges/Toph/](Online%20Judges/Toph/) | 17 |
| **SPOJ** | [Online Judges/Spoj/](Online%20Judges/Spoj/) | 16 |
| **LeetCode** | [Online Judges/LeetCode/](Online%20Judges/LeetCode/) | 10 |
| **HackerRank** | [Online Judges/Hackerrank/](Online%20Judges/Hackerrank/) | 8 |
| **Devskill** | [Online Judges/Devskill/](Online%20Judges/Devskill/) | 8 |
| **CodeChef** | [Online Judges/CodeChef/](Online%20Judges/CodeChef/) | 2 |
| **Total** | | **564** |

---

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
