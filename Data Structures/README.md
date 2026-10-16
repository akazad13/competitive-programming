# Data Structures

This directory contains standard and advanced competitive programming data structures:

| Data Structure | Directory / File | Description | Operations & Complexity |
|---|---|---|---|
| **AVL Tree** | `AVL-tree/AVL-tree-main/AVL.cpp` | Self-balancing binary search tree | Insert, Delete, Search in $O(\log n)$ |
| **Order-Statistic AVL Tree** | `AVL-tree/AVL-tree-to-find-nth-min/nth min.cpp` | AVL tree augmented with subtree size | Find $k$-th minimum element in $O(\log n)$ |
| **Segment Tree (Point Update)** | `Segment-Tree/make query update.cpp` | Range Maximum Query with single-point updates | Build $O(n)$, Query/Update $O(\log n)$ |
| **Segment Tree (Lazy Propagation)** | `Segment-Tree/Lazy Propagation.cpp` | Range sum query with range addition updates | Build $O(n)$, Range Query/Update $O(\log n)$ |
| **2D Segment Tree (Quadtree)** | `Segment-Tree/2D segmented tree.cpp` | 2D spatial grid range maximum queries | Build $O(NM)$, Query $O(\log N \log M)$ |
| **Segment Tree Max Subarray Sum** | `Segment-Tree/Buet segment max sum.cpp` | Range maximum contiguous subarray sum (GSS1/3) | Query/Update $O(\log n)$ |
| **Matrix Exponentiation** | `Matrix-expo/template.cpp` | General $K \times K$ matrix binary exponentiation | $O(K^3 \log P)$ |
| **Fast 2x2 Matrix Expo** | `Matrix-expo/memory efficient.cpp` | In-place $2 \times 2$ matrix power for Fibonacci numbers | $O(\log n)$, $O(1)$ auxiliary space |
| **Mo's Algorithm** | `Mo-offline-Algo/Mo.cpp` | Sqrt decomposition for offline range queries | $O((N + Q) \sqrt{N})$ |
| **Inversion Count (Merge Sort)** | `Merge-Sort/inversion_count_merge_sort.cpp` | Count inverted pairs via divide and conquer | $O(n \log n)$ time, $O(n)$ space |
| **Minimum Swaps to Sort** | `minswap.cpp` | Minimum element swaps to sort an array via cycle detection | $O(n \log n)$ time, $O(n)$ space |
