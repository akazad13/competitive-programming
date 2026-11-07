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
- `docs/adr/`: Architecture Decision Records documenting design standards, invariants, and rationale ([ADR Index](docs/adr/README.md)).
- `Starting Template.cpp`: Standard contest template with fast I/O macros.

---

## 2. Inviolable Architectural Invariants

All coding agents must uphold the following invariants, established in [ADR-0002](docs/adr/0002-cpp-standard-and-template-structure.md):

1. **Fast I/O & Stream Synchronization**:
   - Always include `ios_base::sync_with_stdio(false); cin.tie(NULL);` in competitive templates.
   - Avoid `std::endl` in loops; always use `'\n'` to avoid premature buffer flushing.
2. **Integer Overflow Guardrails**:
   - Use `long long` (`int64_t`) for cumulative calculations, factorials, matrix multiplication, and modular arithmetic to prevent 32-bit integer overflow.
3. **Multi-Test Case State Sanitization**:
   - For multi-test case problems (`int t; cin >> t; while(t--)`), every global array, adjacency list, and DP memoization table must be reset (`memset` or `.clear()`) at the start of each iteration.
4. **Self-Contained Submissions**:
   - Every solution and algorithmic template must remain self-contained in a single file with zero external non-standard dependencies, ready for direct copy-paste submission to online judges.
5. **Code Quality & Complexity**:
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

## 4. Testing Paradigm & Agentic Verification

All autonomous agents must follow the Competitive TDD workflow codified in [ADR-0003](docs/adr/0003-testing-paradigm-and-agentic-verification.md) before completing a solution:

1. **Competitive TDD Cycle (Sample-First)**:
   - **RED**: Capture sample I/O into `input.txt` and `expected.txt`. Verify initial code fails or asserts pending state.
   - **GREEN**: Implement minimal, asymptotically sound algorithm to pass sample test cases.
   - **REFACTOR**: Optimize asymptotic complexity and clean idioms without changing I/O behavior.
2. **I/O Redirection & Exact Format Assertion**:
   - Run `./solution < input.txt > output.txt` and compare strictly with `diff -u output.txt expected.txt`.
   - Ensure zero presentation discrepancies (trailing spaces, missing newlines, case labels).
3. **Multi-Test Case State Isolation**:
   - Replay duplicate test cases consecutively (`t = 2` with identical payloads) to verify that outputs match identically and no global state bleeds across iterations.
4. **Edge Case & Overflow Checklist**:
   - Verify boundary conditions: $N=0, 1$, negative numbers, disconnected topologies, maximum constraints ($N=10^5, 10^6$).
   - Verify 64-bit integer safety: Ensure calculations exceeding $2 \times 10^9$ use `long long` (`int64_t`).
5. **Sanitizer & Diagnostic Gates**:
   - Must compile with `-Wall -Wextra` without warnings.
   - For memory corruption, array bounds, or undefined behavior, verify clean execution under `-fsanitize=address,undefined -g`.

---

## 5. Architecture Decision Records (ADRs)

This repository documents technical decisions, template standards, and architectural trade-offs using ADRs in [`docs/adr/`](docs/adr/README.md).

- **Consult ADRs First**: Before proposing structural or paradigm changes, review existing ADRs in `docs/adr/` to understand past decisions and constraints.
- **Recording New Decisions**: When introducing a major architectural change, new baseline requirements, or structural modifications to standard templates, author a new ADR following the conventions defined in [ADR-0001: Record Architecture Decisions](docs/adr/0001-record-architecture-decisions.md).
- **Index Maintenance**: Whenever a new ADR is added or updated, maintain the table in [docs/adr/README.md](docs/adr/README.md).
