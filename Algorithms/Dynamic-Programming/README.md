# Dynamic Programming (DP) Paradigms & Algorithms

Dynamic Programming solves complex problems by breaking them down into simpler **overlapping subproblems** that exhibit **optimal substructure**. This guide details the theory, recurrences, and implementations for each DP topic in this folder.

---

## 1. 0-1 Knapsack Problem (`0-1 Napsack Problem/`)

### Theory & Formulation
Given $N$ items with weights $w_1, \dots, w_N$ and profits $c_1, \dots, c_N$, and a knapsack of maximum capacity $W$. Each item can be taken at most once.

### Recurrence
$$\text{dp}(i, w) = \begin{cases} 
0 & \text{if } i > N \text{ or } w \le 0 \\
\text{dp}(i+1, w) & \text{if } w_i > w \\
\max(\text{dp}(i+1, w), \; c_i + \text{dp}(i+1, w - w_i)) & \text{if } w_i \le w
\end{cases}$$

- **Complexity:** $O(N \cdot W)$ time, $O(N \cdot W)$ space (reducible to $O(W)$ 1D array by iterating weights backwards from $W$ down to $w_i$).

---

## 2. Subset Sum / Coin Change Reachability (`Coin-Change-is-make/`)

### Problem
Determine if a target sum $S$ can be formed by choosing a subset from given coin denominations.

### State & Transition
$\text{dp}[j]$ is true if sum $j$ is reachable:
$$\text{dp}[i][j] = \text{dp}[i - 1][j] \lor \text{dp}[i - 1][j - \text{coin}_i]$$
- **1D Space Optimization:** Traverse $j$ from $S$ down to $\text{coin}_i$:
  $$\text{dp}[j] = \text{dp}[j] \lor \text{dp}[j - \text{coin}_i]$$
- **Complexity:** $O(N \cdot S)$ time, $O(S)$ space.

---

## 3. Digit DP (`Digit-Dp/`)

### Concept & Intuition
Digit DP counts integers in a range $[A, B]$ that satisfy specific digit-level properties (e.g. divisible by $K$, sum of digits divisible by $K$, containing specific digit patterns).
Instead of checking each number, compute $f(B) - f(A - 1)$ where $f(X)$ processes the decimal representation of $X$ from most significant to least significant digit.

### Universal State Representation
$$\text{dp}(\text{pos}, \text{state}, \text{tight}, \text{started})$$
- `pos`: current digit index being decided ($0 \le \text{pos} < \text{len}$).
- `state`: problem-specific accumulator (e.g., $\text{DigitSum} \pmod K$ and $\text{num} \pmod K$).
- `tight`: boolean flag. If true, the current digit cannot exceed the digit in the upper bound $X[\text{pos}]$. If false, digits can range freely from $0$ to $9$.
- `started`: boolean flag handling leading zeros when required.

### Transitions
For digit $d \in [0, \text{limit}]$ where $\text{limit} = \text{tight} \; ? \; (X[\text{pos}] - '0') : 9$:
$$\text{NextTight} = \text{tight} \land (d == \text{limit})$$
$$\text{NextState} = \text{update}(\text{state}, d)$$
$$\text{res} = \sum_{d} \text{dp}(\text{pos} + 1, \text{NextState}, \text{NextTight})$$

- **Complexity:** $O(\text{len} \cdot |\text{state}| \cdot 10)$ time, highly efficient for $N \le 10^{18}$ ($\text{len} \le 18$).

---

## 4. Inclusion-Exclusion Principle with Bitmask DP (`Inclusion-exclusion/`)

### Theory
Given a set of properties $P_1, P_2, \dots, P_N$, the size of the union of items having at least one property is:
$$\left| \bigcup_{i=1}^N A_i \right| = \sum_{\emptyset \ne S \subseteq \{1, \dots, N\}} (-1)^{|S| - 1} \left| \bigcap_{i \in S} A_i \right|$$

### Bitmask Implementation
For $N$ primes or divisors $a_0, a_1, \dots, a_{N-1}$:
1. Represent each non-empty subset as an integer bitmask $m \in [1, 2^N - 1]$.
2. Compute $\text{LCM}(m)$ for the active bits in $m$.
3. If the number of set bits `__builtin_popcount(m)` is **odd**, **add** $\lfloor X / \text{LCM}(m) \rfloor$.
4. If the number of set bits is **even**, **subtract** $\lfloor X / \text{LCM}(m) \rfloor$.
- **Complexity:** $O(2^N \log(\text{MAX}))$ time, optimal for $N \le 20$.

---

## 5. Maximum Contiguous Subarray Sum (Kadane's Algorithm) (`Kadane-algo/`)

### 1D Kadane
Maintains the maximum subarray sum ending at current index $i$:
$$\text{CurSum}_i = \max(A[i], \; \text{CurSum}_{i-1} + A[i])$$
$$\text{MaxSum} = \max_i (\text{CurSum}_i)$$
- **Index Reconstruction:** Track the start pointer: whenever $\text{CurSum}_{i-1} < 0$, reset start index to $i$.
- **Complexity:** $O(N)$ time, $O(1)$ space.

### 2D Kadane (Max Sum Submatrix) (`Max-sum-2D-subrectengular-Matrix-by-Kadane-algo/`)
Finds the rectangle in a 2D matrix $M[R][C]$ with maximum sum:
1. Fix all pairs of column boundaries $(L, R)$ where $0 \le L \le R < C$.
2. For each row $i$, compress the columns into a 1D array: $\text{RowSum}[i] = \sum_{j=L}^R M[i][j]$.
3. Run 1D Kadane on $\text{RowSum}$ across all rows $0 \dots R - 1$.
- **Complexity:** $O(\text{Cols}^2 \cdot \text{Rows})$ time, $O(\text{Rows})$ space.

---

## 6. Catalan Numbers & Structurally Unique BSTs (`No-of-possible-BST/`)

### Theory
The number of structurally unique Binary Search Trees (BSTs) storing values $1 \dots N$ equals the $N$-th Catalan number $C_N$:
$$C_N = \sum_{i=0}^{N-1} C_i \cdot C_{N - 1 - i}, \quad C_0 = 1, \; C_1 = 1$$
- **Intuition:** Choosing key $i$ ($1 \le i \le N$) as the root leaves $(i - 1)$ keys in the left subtree and $(N - i)$ keys in the right subtree. The combinations multiply independently.
- **Closed Form:** $C_N = \frac{1}{N + 1} \binom{2N}{N}$.
- **Complexity:** $O(N^2)$ using DP, or $O(N)$ using the multiplicative formula.

---

## 7. Travelling Salesperson Problem (TSP) with Bitmask DP (`Travelling salesman/`)

### State Representation
Given $N$ cities ($N \le 18$) and pairwise travel costs $\text{cost}[u][v]$:
- Let $\text{mask} \in [0, 2^N - 1]$ represent the set of visited cities.
- State: $\text{dp}(\text{mask}, u)$ = minimum cost to visit all remaining unvisited cities starting from city $u$.

### Transition
$$\text{dp}(\text{mask}, u) = \min_{v \notin \text{mask}} \Big( \text{cost}[u][v] + \text{dp}(\text{mask} \cup \{v\}, v) \Big)$$
- **Base Case:** When $\text{mask} == (1 \ll N) - 1$ (all cities visited), return $\text{cost}[u][\text{start}]$ to complete the tour.
- **Complexity:** $O(N^2 \cdot 2^N)$ time and $O(N \cdot 2^N)$ space.
