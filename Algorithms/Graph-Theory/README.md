# Graph Theory Algorithms & Advanced Techniques

This guide provides in-depth conceptual, algorithmic, and complexity documentation for every graph algorithm implemented in this repository.

---

## Table of Contents
1. [Graph Traversals (BFS, 2D Grid BFS, 0-1 BFS, DFS)](#1-graph-traversals)
2. [Shortest Paths (Dijkstra, Bellman-Ford, Floyd-Warshall)](#2-shortest-paths)
3. [Minimum Spanning Trees & Disjoint Sets (Kruskal, Prim, DSU)](#3-minimum-spanning-trees--disjoint-sets)
4. [Connectivity & Cut Elements (Articulation Points, Bridges, SCC)](#4-connectivity--cut-elements)
5. [2-Satisfiability (2-SAT)](#5-2-satisfiability-2-sat)
6. [Topological Sorting (Kahn's in-degree & DFS finish time)](#6-topological-sorting)
7. [Maximum Network Flow (Edmonds-Karp & Dinic's Algorithm)](#7-maximum-network-flow)
8. [Heavy-Light Decomposition (HLD)](#8-heavy-light-decomposition-hld)
9. [Stable Marriage Problem (Gale-Shapley Algorithm)](#9-stable-marriage-problem)

---

## 1. Graph Traversals

### Breadth-First Search (`BFS/bfs_graph.cpp` & `bfs_grid.cpp`)
- **Concept:** Explores vertices in increasing order of distance from source using a FIFO `std::queue`.
- **Applications:** Single-source shortest path in unweighted graphs, connected component discovery, bipartite graph testing.
- **2D Grid Variant:** Transitions to neighbors using direction arrays `fx[] = {1, -1, 0, 0}` and `fy[] = {0, 0, 1, -1}` with bounds validation.
- **Complexity:** $O(V + E)$ time, $O(V)$ space ($O(R \cdot C)$ on grids).

### 0-1 BFS (`0-1-BFS-using-deque/zeroOneBfs.cpp`)
- **Concept:** When edge weights are strictly $0$ or $1$, Dijkstra's $O(E \log V)$ priority queue overhead can be avoided by using a double-ended queue (`std::deque`).
- **Rule:** If relaxing along an edge of weight $0$, push to the **front** of the deque. If weight $1$, push to the **back**.
- **Complexity:** $O(V + E)$ optimal linear time.

### Depth-First Search (`DFS/dfs.cpp`)
- **Concept:** Explores as deep as possible along each branch before backtracking using recursive calls.
- **Applications:** Cycle detection, path discovery, topological sort, flood fill.
- **Complexity:** $O(V + E)$ time, $O(V)$ recursion stack.

---

## 2. Shortest Paths

### Dijkstra's Algorithm (`Dijkstra-shortest-path-algorithm/solution.cpp`)
- **Concept:** Greedy algorithm maintaining a min-priority queue of $(d[u], u)$. Always expands the unvisited vertex with smallest tentative distance.
- **Condition:** All edge weights must be non-negative ($w \ge 0$).
- **Stale Entry Pruning:** `if (top.dist > d[u]) continue;` eliminates the need for expensive decrease-key operations.
- **Complexity:** $O((V + E) \log V)$ time with binary min-heap, $O(V + E)$ space.

### Bellman-Ford Algorithm (`Belmon-Ford/source.cpp`)
- **Concept:** Relaxes all $E$ edges $(u, v, w)$ sequentially for $V - 1$ rounds. Any shortest path contains at most $V - 1$ edges.
- **Negative Cycles:** If any edge relaxes in round $V$, a negative-weight cycle is reachable from the source.
- **Complexity:** $O(V \cdot E)$ time, $O(V + E)$ space.

### Floyd-Warshall Algorithm (`Floyed-Warshall/Floyed war.cpp`)
- **Concept:** Dynamic programming approach computing all-pairs shortest paths by evaluating all intermediate vertices $k \in [1, V]$:
  $$d[i][j] = \min(d[i][j], \; d[i][k] + d[k][j])$$
- **Path Reconstruction:** Maintain `Next[i][j] = Next[i][k]` whenever an intermediate vertex $k$ improves the path from $i$ to $j$.
- **Complexity:** $O(V^3)$ time, $O(V^2)$ space.

---

## 3. Minimum Spanning Trees & Disjoint Sets

### Disjoint Set Union (DSU / Union-Find) (`Disjoint_set/`)
- **Concept:** Maintains a partition of elements into disjoint dynamic sets with two operations:
  - `find(x)`: returns the canonical representative of the set containing $x$. Optimized with **Path Compression** (`par[x] = find(par[x])`).
  - `union(x, y)`: merges sets containing $x$ and $y$. Optimized with **Union by Size / Rank**.
- **Complexity:** $O(\alpha(N)) \approx O(1)$ amortized per operation, where $\alpha$ is the Inverse Ackermann function.

### Kruskal's MST (`MST-Kruskal/source code1.cpp`)
- **Concept:** Greedily sorts all edges by weight in non-decreasing order and adds edges that connect two different DSU components until $V - 1$ edges are added.
- **Complexity:** $O(E \log E) = O(E \log V)$ time, $O(V + E)$ space.

### Prim's MST (`MST_Primes/source code1.cpp`)
- **Concept:** Grows a single component starting from source vertex $s$, greedily picking the minimum-weight cut edge connecting a visited vertex to an unvisited vertex using a min-heap.
- **Complexity:** $O((V + E) \log V)$ time with priority queue.

---

## 4. Connectivity & Cut Elements

### Articulation Points (Cut Vertices) (`articulation-point/arti.cpp`)
- **Definition:** A vertex whose removal strictly increases the number of connected components.
- **Condition:** In DFS tree, vertex $u$ is an articulation point if:
  1. $u$ is the root of the DFS tree and has $\ge 2$ children.
  2. $u$ is not the root, and has a child $v$ such that $\text{low}[v] \ge \text{discovery}[u]$.

### Bridges (Cut Edges) (`bridge/bridge.cpp`)
- **Definition:** An edge $(u, v)$ whose removal increases the number of connected components.
- **Condition:** Edge $(u, v)$ is a bridge if child $v$ cannot reach $u$ or its ancestors via back-edges:
  $$\text{low}[v] > \text{discovery}[u]$$
- **Complexity:** $O(V + E)$ single-pass DFS for both.

### Strongly Connected Components (SCC)
- **Definition:** Maximal subgraph of a directed graph where every vertex is reachable from every other vertex.
- **Kosaraju's Algorithm (`SCC.cpp`):**
  1. Run DFS on $G$, recording vertices by finishing time.
  2. Transpose graph $G^T$ (reverse all directed edges).
  3. Run DFS on $G^T$ in decreasing order of recorded finish times.
- **Tarjan's Algorithm (`targenSCC.cpp`):**
  Single DFS pass tracking $\text{low}[u]$ using an explicit stack of active vertices.
- **Complexity:** $O(V + E)$ linear time for both.

---

## 5. 2-Satisfiability (2-SAT) (`2 - SAT/2sat.cpp`)

### Formulation
Given a boolean formula in 2-CNF: $(x_1 \lor y_1) \land (x_2 \lor y_2) \land \dots \land (x_M \lor y_M)$.

### Implication Graph Construction
Each clause $(A \lor B)$ is equivalent to two directed implications:
$$\neg A \implies B \quad \text{and} \quad \neg B \implies A$$
Construct a directed graph with $2N$ vertices: $x_i$ and $\neg x_i$.

### Satisfiability Criteria
The formula is satisfiable **if and only if** no variable $x_i$ and its negation $\neg x_i$ belong to the same Strongly Connected Component (SCC):
$$\forall i, \; \text{SCC}(x_i) \ne \text{SCC}(\neg x_i)$$
- **Value Assignment:** If satisfiable, assign $x_i = \text{true}$ if $\text{SCC}(x_i) > \text{SCC}(\neg x_i)$ in topological order (earlier in condensation DAG), else $\text{false}$.
- **Complexity:** $O(V + E)$ linear time using Tarjan's or Kosaraju's algorithm.

---

## 6. Topological Sorting

### Kahn's Algorithm (In-Degree BFS) (`Topological-Sorting/TS-Algorithm.cpp`)
1. Compute $\text{inDegree}[u]$ for all vertices.
2. Push all vertices with $\text{inDegree} == 0$ into a queue.
3. Dequeue $u$, append $u$ to topological order, and decrement $\text{inDegree}[v]$ for all edges $(u, v)$.
4. If $\text{inDegree}[v]$ becomes 0, push $v$ into the queue.
5. If processed vertices $< V$, the graph contains a **cycle**.

### DFS Finish Times (`Topological-sort-using-DFS/solution.cpp`)
1. Run DFS. When a vertex finishes all explorations, prepend it to the ordering.
- **Complexity:** $O(V + E)$ for both.

---

## 7. Maximum Network Flow

### Edmonds-Karp Algorithm (`Ford-Fulkarson-Max-Flow/maxFlow.cpp`)
- **Concept:** Implementation of the Ford-Fulkerson method that chooses the shortest augmenting path from source $s$ to sink $t$ using BFS on the residual graph.
- **Complexity:** $O(V \cdot E^2)$ time.

### Dinic's Algorithm (`Dinic algo.cpp`)
- **Concept:** Computes maximum flow in phases using two alternating steps:
  1. **BFS Step:** Constructs a **Level Graph** (layered network) from $s$ to $t$.
  2. **DFS Step:** Pushes **blocking flows** along admissible edges (where $\text{level}[v] == \text{level}[u] + 1$).
- **Complexity:** $O(V^2 \cdot E)$ for general networks; $O(E \sqrt{V})$ for unit networks / bipartite matching.

---

## 8. Heavy-Light Decomposition (HLD) (`HLD/`)

### Purpose
Supports path queries (path sum, path max edge) and path updates between any two nodes $u, v$ in an arbitrary tree in $O(\log^2 N)$ time.

### Mechanism
1. **Subtree Size Calculation:** Run DFS to calculate subtree sizes for each node.
2. **Heavy vs Light Edges:** For each node $u$, the child $v$ with the largest subtree size is connected by a **heavy edge**. All other children are connected by **light edges**.
3. **Chain Flattening:** Heavy edges form continuous heavy chains. Map chains into contiguous ranges in a 1D Segment Tree base array.
4. **Path Traversal:** Querying path $(u, v)$ traverses at most $O(\log N)$ light edges (jumping across chains). Each chain segment is queried in $O(\log N)$ on the segment tree, giving $O(\log^2 N)$ per query.
- **Complexity:** $O(N)$ preprocessing, $O(\log^2 N)$ query, $O(\log N)$ point update.

---

## 9. Stable Marriage Problem (`Stable-Marriage-Problem/algo.cpp`)

### Problem
Given $N$ men and $N$ women with ranked preferences, match them into $N$ pairs such that no man and woman prefer each other over their assigned partners (no unstable blocking pair).

### Gale-Shapley Algorithm
1. Initialize all men and women as single.
2. While there is a free man $m$ who has not proposed to every woman:
   - $m$ proposes to his highest-ranked woman $w$ to whom he has not yet proposed.
   - If $w$ is free, $(m, w)$ engage.
   - If $w$ is engaged to $m'$:
     - If $w$ prefers $m$ over $m'$, $m'$ becomes free and $(m, w)$ engage.
     - Else, $w$ rejects $m$ and $m$ remains free.
- **Properties:** Always terminates in $\le N^2$ proposals with a male-optimal stable matching.
- **Complexity:** $O(N^2)$ time and $O(N^2)$ space.
