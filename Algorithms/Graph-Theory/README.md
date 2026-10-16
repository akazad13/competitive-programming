# Graph Theory Algorithms

This directory contains implementations of classic and advanced graph theory algorithms:

| Algorithm / Problem | Subdirectory / File | Description | Time Complexity | Space Complexity |
|---|---|---|---|---|
| **Breadth-First Search (Adjacency List)** | `BFS/bfs_graph.cpp` | Unweighted shortest path & tree traversal | $O(V + E)$ | $O(V + E)$ |
| **Breadth-First Search (2D Grid)** | `bfs_grid.cpp` | Shortest path on a 2D grid with 4-way moves | $O(R \cdot C)$ | $O(R \cdot C)$ |
| **0-1 BFS (Deque)** | `0-1-BFS-using-deque/zeroOneBfs.cpp` | Shortest path on graphs with edge weights in {0, 1} | $O(V + E)$ | $O(V + E)$ |
| **Depth-First Search** | `DFS/dfs.cpp` | Graph traversal & connected components | $O(V + E)$ | $O(V + E)$ |
| **Dijkstra's Algorithm** | `Dijkstra-shortest-path-algorithm/solution.cpp` | Single-source shortest path for non-negative edge weights | $O((V + E) \log V)$ | $O(V + E)$ |
| **Bellman-Ford Algorithm** | `Belmon-Ford/source.cpp` | Single-source shortest path with negative edges & cycle check | $O(V \cdot E)$ | $O(V + E)$ |
| **Floyd-Warshall Algorithm** | `Floyed-Warshall/Floyed war.cpp` | All-pairs shortest paths with path reconstruction | $O(V^3)$ | $O(V^2)$ |
| **Kruskal's MST** | `MST-Kruskal/source code1.cpp` | Minimum Spanning Tree using Disjoint Set Union | $O(E \log E)$ | $O(V + E)$ |
| **Prim's MST** | `MST_Primes/source code1.cpp` | Minimum Spanning Tree using min-priority queue | $O((V + E) \log V)$ | $O(V + E)$ |
| **Disjoint Set Union (DSU)** | `Disjoint_set/` | Fast Union-Find with path compression and component tracking | $O(\alpha(V)) \approx O(1)$ | $O(V)$ |
| **Articulation Points** | `Articulation-point-and-bridge/articulation-point/arti.cpp` | Finds cut vertices using DFS low-link | $O(V + E)$ | $O(V + E)$ |
| **Bridges (Cut Edges)** | `Articulation-point-and-bridge/bridge/bridge.cpp` | Finds cut edges using DFS low-link | $O(V + E)$ | $O(V + E)$ |
| **Kosaraju's SCC** | `Strongly-Connected-Component/SCC.cpp` | Strongly Connected Components via two-pass DFS | $O(V + E)$ | $O(V + E)$ |
| **Tarjan's SCC** | `Strongly-Connected-Component/targenSCC.cpp` | Strongly Connected Components via single-pass DFS | $O(V + E)$ | $O(V + E)$ |
| **2-SAT** | `2 - SAT/2sat.cpp` | 2-Satisfiability via implication graph and SCC | $O(V + E)$ | $O(V + E)$ |
| **Topological Sort (Kahn's)** | `Topological-Sorting/TS-Algorithm.cpp` | Linear DAG vertex ordering using in-degrees | $O(V + E)$ | $O(V + E)$ |
| **Topological Sort (DFS)** | `Topological-sort-using-DFS/solution.cpp` | Linear DAG vertex ordering using DFS finish times | $O(V + E)$ | $O(V + E)$ |
| **Edmonds-Karp Max Flow** | `Ford-Fulkarson-Max-Flow/maxFlow.cpp` | Network flow using augmenting paths with BFS | $O(V \cdot E^2)$ | $O(V^2)$ |
| **Dinic's Max Flow** | `Dinic algo.cpp` | Network flow using layered networks and blocking flows | $O(V^2 \cdot E)$ | $O(V + E)$ |
| **Heavy-Light Decomposition (HLD)** | `HLD/pathcostHLD.cpp` | Tree decomposition for path sum queries & updates | $O(\log^2 N)$ per query | $O(N \log N)$ |
| **HLD Max Edge on Path** | `HLD/max edge in path.cpp` | Tree path maximum edge queries & updates | $O(\log^2 N)$ per query | $O(N \log N)$ |
| **Stable Marriage Problem** | `Stable-Marriage-Problem/algo.cpp` | Gale-Shapley stable matching algorithm | $O(N^2)$ | $O(N^2)$ |
