# Backtracking Algorithms & Combinatorial Search

Backtracking is an algorithmic paradigm for solving constraint satisfaction and combinatorial optimization problems. It systematically builds candidates for solutions step-by-step and **abandons a candidate ("backtracks")** as soon as it determines the candidate cannot lead to a valid full solution.

---

## 1. Core Principles of Backtracking

Every backtracking solution traverses an implicit **State-Space Tree**:
```
                    [ Root: Empty State ]
                   /          |          \
             [Choice 1]   [Choice 2]   [Choice 3]
              /      \        |            |
          [Valid]  [Pruned] [Pruned]    [Valid]
            /                               |
       [Solution]                      [Solution]
```

### General Template
```cpp
void backtrack(State state) {
    if (is_solution(state)) {
        record_or_print(state);
        return;
    }
    for (Candidate choice : get_candidates(state)) {
        if (is_promising(choice, state)) { // Pruning check (bounding function)
            apply(choice, state);
            backtrack(state);
            revert(choice, state);          // Backtrack step
        }
    }
}
```

---

## 2. Graph M-Coloring (`Graph-cloring/Gcoloring.cpp`)

### Problem Statement
Given an undirected graph $G = (V, E)$ and an integer $M$, determine whether vertices can be assigned colors $1 \dots M$ such that no two adjacent vertices share the same color.

### Algorithmic Mechanism
1. Order vertices $0, 1, \dots, V - 1$.
2. At vertex $u$:
   - Try assigning color $c \in \{1, \dots, M\}$.
   - **Safety / Bounding Check:** Verify that no neighbour $v$ of $u$ ($G[u][v] == 1$) has already been assigned color $c$.
   - If safe, assign `color[u] = c` and recursively color vertex $u + 1$.
   - If all $V$ vertices are successfully colored, return `true`.
   - If no color in $\{1, \dots, M\}$ is valid for $u$, backtrack by setting `color[u] = 0` and return `false`.

### Complexity
- **Time Complexity:** $O(M^V)$ in the worst case (searching an $M$-ary tree of depth $V$). In practice, strong pruning cuts down subtrees drastically.
- **Space Complexity:** $O(V)$ for the color assignment array and recursion call stack.

---

## 3. N-Queens Problem (`N-Queen/NQueen.cpp`)

### Problem Statement
Place $N$ chess queens on an $N \times N$ chessboard such that no two queens attack each other (i.e. no two queens share the same row, column, or diagonal).

### Algorithmic Mechanism
1. Since each row must contain exactly one queen, represent the state as placing one queen per row $r \in \{0, \dots, N - 1\}$ across columns $c \in \{0, \dots, N - 1\}$.
2. At row $r$, iterate through column $c \in \{0, \dots, N - 1\}$:
   - Check if column $c$ is under attack.
   - Check major diagonal: $(r - c)$ is constant along $\searrow$ diagonals.
   - Check minor diagonal: $(r + c)$ is constant along $\nearrow$ diagonals.
3. If safe:
   - Place queen at $(r, c)$.
   - Recurse to row $r + 1$.
   - If row $r + 1$ search fails, unplace queen at $(r, c)$ and try the next column.

### Bitmask Optimization
Using three bitmask integers (`col_mask`, `diag1_mask`, `diag2_mask`), safety checks and queen placements take $O(1)$ bitwise operations:
```cpp
void solveNQueens(int row, int col_mask, int d1_mask, int d2_mask, int N) {
    if (row == N) { count++; return; }
    int available = ((1 << N) - 1) & ~(col_mask | d1_mask | d2_mask);
    while (available) {
        int p = available & -available; // Lowest set bit
        available -= p;
        solveNQueens(row + 1, col_mask | p, (d1_mask | p) << 1, (d2_mask | p) >> 1, N);
    }
}
```

### Complexity
- **Time Complexity:** $O(N!)$ upper bound. For $N = 8$, the search explores only 2,057 nodes instead of $8^8 \approx 1.6 \times 10^7$.
- **Space Complexity:** $O(N^2)$ for 2D board or $O(N)$ with column/diagonal boolean masks.
