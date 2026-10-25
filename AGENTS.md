# AGENTS.md — AI Agent Guidance & Repository Rules

This document provides mandatory guidance for autonomous AI coding agents (Antigravity, Claude Code, GitHub Copilot, Cursor, Windsurf, Devin) operating in `akazad13/competitive-programming`.

---

## 1. System Identity & Architecture

**Product**: `Competitive Programming` — Algorithmic problem-solving library, data structures catalog, and 560+ accepted solutions across global online judges (UVA, LightOJ, SPOJ, LeetCode, CodeChef, HackerRank).
- **Language**: Modern C++ (C++17 / C++20).
- **Core Standard**: Strict memory bounds, optimal asymptotic complexity ($O(N \log N)$, $O(N)$), fast I/O.

### Project Layout:
- `Algorithms/`: Graph theory (Dijkstra, Floyd-Warshall, Dinic Flow, 2-SAT, Tarjan SCC), Dynamic Programming (Bitmask, Knapsack, LIS), Strings (KMP, Z, Trie), Geometry.
- `Data Structures/`: Segment Tree (Lazy propagation), Fenwick (BIT), AVL Trees, Disjoint Set Union (DSU), Mo's Sqrt Decomposition.
- `Math/`: Number theory (Sieve, Miller-Rabin, Modular Arithmetic, Lucas Theorem, Extended GCD), Matrix Exponentiation, Combinatorics.
- `Online Judges/`: Categorized accepted solutions (`UVA/`, `LightOJ/`, `SPOJ/`, `LeetCode/`, `HackerRank/`, `CodeChef/`).
- `Starting Template.cpp`: Standard contest template with fast I/O macros.

---

## 2. Inviolable Architectural Invariants

1. **Fast I/O & Stream Synchronization**:
   - Always include `ios_base::sync_with_stdio(false); cin.tie(NULL);` in competitive templates.
   - Avoid `std::endl` in loops; always use `'\n'` to avoid premature buffer flushing.
2. **Integer Overflow Guardrails**:
   - Use `long long` (`int64_t`) for cumulative calculations, factorials, matrix multiplication, and modular arithmetic to prevent 32-bit integer overflow.
3. **Multi-Test Case State Sanitization**:
   - For multi-test case problems (`int t; cin >> t; while(t--)`), every global array, adjacency list, and DP memoization table must be reset (`memset` or `.clear()`) at the start of each iteration.
4. **Code Quality**:
   - Preserve clean variable naming and add time/space complexity comments (`// Time: O(N log N), Space: O(N)`) to new solutions.

---

## 3. Commands Cheat Sheet

```bash
# Compile solution with C++20 and warnings
g++ -std=c++20 -O2 -Wall -Wextra solution.cpp -o solution

# Run with redirected input and output
./solution < input.txt > output.txt

# Run with AddressSanitizer & UndefinedBehaviorSanitizer (debugging UB)
g++ -std=c++20 -fsanitize=address,undefined -g solution.cpp -o solution
```

---

## 4. Verification Gates for AI Agents

Before submitting code changes or finishing a turn:
1. Verify that solutions compile with `-Wall -Wextra` without warnings.
2. Verify corner cases ($N=0, 1$, large inputs, negative values).
