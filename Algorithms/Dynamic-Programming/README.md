# Dynamic Programming (DP) Algorithms

This directory contains implementations of fundamental and advanced dynamic programming paradigms:

| Topic / Problem | Subdirectory | Description | Complexity |
|---|---|---|---|
| **0-1 Knapsack** | `0-1 Napsack Problem/` | Top-down memoization for the classic 0-1 knapsack problem with documentation. | $O(N \cdot W)$ |
| **Coin Change / Subset Sum** | `Coin-Change-is-make/` | Determines reachability of target sum using given coin denominations. | $O(N \cdot S)$ |
| **Digit DP (Divisibility)** | `Digit-Dp/digitDP.cpp` | Counts numbers in range $[A, B]$ divisible by $K$ with digit sum divisible by $K$. | $O(\text{len} \cdot K^2)$ |
| **Digit DP (Distinct Digits)** | `Digit-Dp/noora number.cpp` | Digit DP with bitmask tracking distinct digits used. | $O(\text{len} \cdot 2^{10})$ |
| **Inclusion-Exclusion DP** | `Inclusion-exclusion/` | Inclusion-Exclusion principle over subsets using bitmask DP and LCM. | $O(2^N \log(\text{val}))$ |
| **Kadane's Algorithm** | `Kadane-algo/` | 1D Maximum contiguous subarray sum and index reconstruction. | $O(N)$ time, $O(1)$ space |
| **2D Kadane (Max Submatrix)** | `Max-sum-2D-subrectengular-Matrix-by-Kadane-algo/` | Maximum sum rectangle in a 2D matrix using column compression. | $O(\text{Cols}^2 \cdot \text{Rows})$ |
| **Combinations nCr modulo M** | `nCr/` | $n\text{C}r \pmod M$ using prime factorization and Legendre's formula. | $O(\text{MAX\_P} + \pi(n) \log n)$ |
| **Number of Possible BSTs** | `No-of-possible-BST/` | Counts structurally unique BSTs with $N$ keys via Catalan numbers. | $O(N^2)$ |
| **Travelling Salesperson (TSP)** | `Travelling salesman/` | Exact minimum cost Hamiltonian cycle using bitmask state DP. | $O(N^2 \cdot 2^N)$ |
