# 0-1 Knapsack Problem

## Problem Statement
Given $n$ items, each with a specific weight $w_i$ and value/cost $c_i$, and a knapsack with maximum weight capacity $W$, determine the maximum value that can be put into the knapsack such that the total weight does not exceed $W$. Each item can either be included or excluded (0 or 1).

## Recurrence Relation
For item $i$ (1-indexed) and remaining capacity $w$:

$$\text{dp}(i, w) = \begin{cases} 
0 & \text{if } i > n \text{ or } w \le 0 \\
\text{dp}(i+1, w) & \text{if } w_i > w \\
\max(\text{dp}(i+1, w), \; c_i + \text{dp}(i+1, w - w_i)) & \text{if } w_i \le w
\end{cases}$$

## Complexity
- **Time Complexity:** $O(n \cdot W)$ pseudo-polynomial time.
- **Space Complexity:** $O(n \cdot W)$ using a 2D table, or $O(W)$ using 1D space optimization.

## Implementations
- `source code.cpp`: Top-down recursion with memoization table.
