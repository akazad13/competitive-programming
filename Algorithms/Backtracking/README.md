# Backtracking Algorithms

This directory contains implementations of classic combinatorial search and constraint-satisfaction problems solved via recursive backtracking:

| Problem | Directory | Description | Worst-case Complexity |
|---|---|---|---|
| **Graph Coloring (M-Coloring)** | `Graph-cloring/Gcoloring.cpp` | Assigns at most $M$ colors to $V$ vertices such that no adjacent vertices share the same color. | $O(M^V)$ time, $O(V)$ space |
| **N-Queens Problem** | `N-Queen/NQueen.cpp` | Places $N$ non-attacking queens on an $N \times N$ chessboard. | $O(N!)$ time, $O(N^2)$ space |
