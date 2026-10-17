<div align="center">

# ⚡ Competitive Programming

### Comprehensive collection of competitive programming templates, standard algorithms, data structures, and 560+ accepted solutions

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Solved Problems](https://img.shields.io/badge/Solved%20Problems-564%20Accepted-success?style=flat-square&logo=codeforces&logoColor=white)](https://github.com/akazad13/competitive-programming)
[![Online Judges](https://img.shields.io/badge/Judges-UVA%20%7C%20LightOJ%20%7C%20SPOJ%20%7C%20LeetCode-orange?style=flat-square)](https://github.com/akazad13/competitive-programming)
[![License](https://img.shields.io/badge/License-MIT-blue?style=flat-square)](LICENSE)

[Overview](#-overview) •
[Mental Checklist](#-contest-mental-checklist) •
[Algorithms](#-1-algorithms) •
[Data Structures](#-2-data-structures) •
[Number Theory](#-3-math--number-theory) •
[Solved Problems](#-4-online-judges-solutions) •
[Template](#-quick-start--template)

</div>

---

## 📌 Overview

**Competitive Programming** is an exhaustive, production-grade repository of algorithmic problem-solving techniques, data structure implementations, fast I/O templates, and accepted solutions to 560+ problems solved across major global online judges (UVA, LightOJ, SPOJ, LeetCode, CodeChef, HackerRank, Devskill, and Toph).

### Key Highlights
- 🧠 **Algorithms Library**: Implements Graph Theory (HLD, Dinic Flow, 2-SAT, Tarjan SCC), Dynamic Programming (Bitmask, Digit DP, 2D Kadane), String Matching (KMP, Z, Aho-Corasick), and Geometry.
- 🌲 **Advanced Data Structures**: Segment Trees (Lazy Propagation, 2D Quadtree, Max Subarray Sum), AVL Trees, Order-Statistic Trees, Mo's Algorithm (Sqrt Decomposition), and Matrix Exponentiation.
- 🔢 **Number Theory & Math**: BigInt arbitrary-precision arithmetic, Segmented Sieve, Miller-Rabin Primality, Modular Inverse, Lucas' Theorem, and Euler's Totient.
- 🏆 **560+ Verified Solutions**: Clean, documented C++ solutions categorized by online judge.

---

## 📋 Contest Mental Checklist

Before submitting any solution during a live contest:
1. **Sub-problem**: Can I solve the simplified or smaller sub-problem first?
2. **Edge Cases**: Did I verify bounds ($N = 0$, $N = 1$, negative inputs, values approaching $10^{18}$)?
3. **Data Types**: Are variables typed as `long long int` where multiplication or cumulative sums exceed $2^{31}-1$?
4. **Memory & Reset**: Are global arrays, vectors, and DP tables cleared (`memset` / `.clear()`) for **each test case**?
5. **Complexity**: Will time and space complexity pass within 1.0s to 2.0s time limits ($~10^8$ operations)?
6. **1-Based vs 0-Based**: Did I verify problem indexing expectations and output formats?

---

## 📂 Repository Structure

```text
competitive-programming/
├── Algorithms/              # Algorithmic paradigms and standard templates
│   ├── Array-Manipulation/  # Sliding window, max product subarray
│   ├── Backtracking/        # N-Queens, M-Coloring
│   ├── Dynamic-Programming/ # Digit DP, Bitmask TSP, 2D Kadane, Knapsack
│   ├── Geometry/            # Shoelace, sweep-line closest pair
│   ├── Graph-Theory/        # Dijkstra, Flow (Dinic), HLD, SCC (Tarjan)
│   ├── Sorting/             # Counting, Radix, Merge, Quick, Heap sort
│   └── String-Processing/   # KMP, Z-algorithm, Rabin-Karp, Tries
├── Data Structures/         # Core and advanced data structures
│   ├── AVL-tree/            # Balanced BST, Order-statistic trees
│   ├── Segment-Tree/        # Point update, lazy propagation, 2D Quadtree
│   └── Mo-offline-Algo/     # Sqrt decomposition range queries
├── Math/                    # Number theory, modular arithmetic, BigInt
├── Online Judges/           # 564 Accepted solutions grouped by platform
│   ├── UVA/                 # 274 Accepted solutions
│   ├── LightOJ/             # 229 Accepted solutions
│   ├── Toph/                # 17 Accepted solutions
│   ├── Spoj/                # 16 Accepted solutions
│   └── LeetCode/            # 10 Accepted solutions
├── Starting Template.cpp    # Optimized C++ competitive template
└── stl.txt                  # STL quick-reference cheatsheet
```

---

## 🔬 1. Algorithms

| Domain | Highlights |
| :--- | :--- |
| **Graph Theory** | BFS/DFS, 0-1 BFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Kruskal & Prim MST, DSU, Articulation Points & Bridges, Kosaraju & Tarjan SCC, 2-SAT, Dinic & Edmonds-Karp Max Flow, Heavy-Light Decomposition (HLD). |
| **Dynamic Programming** | 0-1 Knapsack, Coin Change, Digit DP, Inclusion-Exclusion, 1D & 2D Kadane, $n\text{C}r$, Catalan BSTs, TSP with Bitmask. |
| **String Processing** | KMP Algorithm, Z-Algorithm, Rabin-Karp Hash, Trie (Array & Pointer), Longest Common Subsequence (LCS), Smallest Cyclic Rotation. |
| **Computational Geometry** | Shoelace Polygon Area, Line Segment Intersection test, Closest Pair of Points (Sweep-line). |
| **Array & Sorting** | Counting Sort, Radix Sort, Merge Sort with Inversion Count, Quick Sort, Sliding Window Unique Subarray. |

---

## 🌲 2. Data Structures

| Data Structure | Capability & Complexity |
| :--- | :--- |
| **Segment Tree (Point Update)** | Range Maximum Query with single-element updates in $O(\log n)$. |
| **Segment Tree (Lazy Propagation)** | Range Sum / Max Query with range updates in $O(\log n)$. |
| **2D Segment Tree (Quadtree)** | 2D matrix subgrid range queries. |
| **AVL & Order-Statistic Tree** | Self-balancing binary search tree finding the $k$-th minimum element in $O(\log n)$. |
| **Mo's Algorithm** | Square Root Decomposition for offline range queries in $O((N + Q) \sqrt{N})$. |
| **Matrix Exponentiation** | Arbitrary $K \times K$ and memory-efficient $2 \times 2$ fast power in $O(K^3 \log P)$. |

---

## 🔢 3. Math & Number Theory

| Topic | Key Algorithms |
| :--- | :--- |
| **Big Number Arithmetic** | Arbitrary-precision BigInt addition, subtraction, division by 2, and multiplication. |
| **Primes & Sieves** | Sieve of Eratosthenes, Bitwise Sieve, Segmented Sieve, Miller-Rabin Primality Testing. |
| **Modular Arithmetic** | Extended Euclidean Algorithm, Modular Inverse, Binary Exponentiation (`mulmod`), Lucas' Theorem, Euler's Totient $\phi$, Divisor Counting $d(n)$. |

---

## 🏆 4. Online Judges Solutions

| Judge / Platform | Accepted Solutions |
| :--- | :---: |
| **UVA Online Judge** | 274 |
| **LightOJ** | 229 |
| **Toph** | 17 |
| **SPOJ** | 16 |
| **LeetCode** | 10 |
| **HackerRank** | 8 |
| **Devskill** | 8 |
| **CodeChef** | 2 |
| **Total Accepted** | **564** |

---

## 🚀 Quick Start & Template

The template in [`Starting Template.cpp`](Starting%20Template.cpp) provides fast I/O and essential typedefs:

```cpp
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

int main() {
    fast_io;
    int t;
    if (cin >> t) {
        while (t--) {
            // solve each test case
        }
    }
    return 0;
}
```

---

## 👤 Author

**Md. Abul Kalam**
- GitHub: [@akazad13](https://github.com/akazad13)
- LinkedIn: [Md. Abul Kalam](https://linkedin.com/in/akazad13)

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
