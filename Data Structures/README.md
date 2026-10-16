# Advanced Data Structures

This directory contains implementations and comprehensive guides for core and advanced competitive programming data structures:

## Sub-Topic Documentation Guides

| Topic | Documentation Guide | Key Implementations |
|---|---|---|
| **Segment Trees** | [`Segment-Tree/README.md`](Segment-Tree/README.md) | Standard Point Update RMQ, Lazy Propagation Range Addition, 2D Quadtree, Range Max Subarray Sum. |
| **AVL Trees** | [`AVL-tree/README.md`](AVL-tree/README.md) | Self-Balancing BST (LL, RR, LR, RL rotations), Order-Statistic Tree ($k$-th element). |
| **Matrix Exponentiation** | [`Matrix-expo/README.md`](Matrix-expo/README.md) | Linear recurrence solving in $O(K^3 \log N)$, fast Fibonacci, in-place $2 \times 2$ power. |
| **Mo's Algorithm** | [`Mo-offline-Algo/README.md`](Mo-offline-Algo/README.md) | Square Root Decomposition for offline range queries in $O((N + Q)\sqrt{N})$. |

---

## Complete Index of Data Structures

| Data Structure | Directory / File | Description | Operations & Complexity |
|---|---|---|---|
| **AVL Tree** | [`AVL-tree/AVL-tree-main/AVL.cpp`](AVL-tree/AVL-tree-main/AVL.cpp) | Self-balancing binary search tree | Insert, Delete, Search in $O(\log n)$ |
| **Order-Statistic AVL Tree** | [`AVL-tree/AVL-tree-to-find-nth-min/nth min.cpp`](AVL-tree/AVL-tree-to-find-nth-min/nth%20min.cpp) | AVL tree augmented with subtree size | Find $k$-th minimum element in $O(\log n)$ |
| **Segment Tree (Point Update)** | [`Segment-Tree/make query update.cpp`](Segment-Tree/make%20query%20update.cpp) | Range Maximum Query with single-point updates | Build $O(n)$, Query/Update $O(\log n)$ |
| **Segment Tree (Lazy Propagation)** | [`Segment-Tree/Lazy Propagation.cpp`](Segment-Tree/Lazy%20Propagation.cpp) | Range sum query with range addition updates | Build $O(n)$, Range Query/Update $O(\log n)$ |
| **2D Segment Tree (Quadtree)** | [`Segment-Tree/2D segmented tree.cpp`](Segment-Tree/2D%20segmented%20tree.cpp) | 2D spatial grid range maximum queries | Build $O(NM)$, Query $O(\log N \log M)$ |
| **Segment Tree Max Subarray Sum** | [`Segment-Tree/Buet segment max sum.cpp`](Segment-Tree/Buet%20segment%20max%20sum.cpp) | Range maximum contiguous subarray sum (GSS1/3) | Query/Update $O(\log n)$ |
| **Matrix Exponentiation** | [`Matrix-expo/template.cpp`](Matrix-expo/template.cpp) | General $K \times K$ matrix binary exponentiation | $O(K^3 \log P)$ |
| **Fast 2x2 Matrix Expo** | [`Matrix-expo/memory efficient.cpp`](Matrix-expo/memory%20efficient.cpp) | In-place $2 \times 2$ matrix power for Fibonacci numbers | $O(\log n)$, $O(1)$ auxiliary space |
| **Mo's Algorithm** | [`Mo-offline-Algo/Mo.cpp`](Mo-offline-Algo/Mo.cpp) | Sqrt decomposition for offline range queries | $O((N + Q) \sqrt{N})$ |
| **Inversion Count (Merge Sort)** | [`Merge-Sort/inversion_count_merge_sort.cpp`](Merge-Sort/inversion_count_merge_sort.cpp) | Count inverted pairs via divide and conquer | $O(n \log n)$ time, $O(n)$ space |
| **Minimum Swaps to Sort** | [`minswap.cpp`](minswap.cpp) | Minimum element swaps to sort an array via cycle detection | $O(n \log n)$ time, $O(n)$ space |
