# ADR-0002: C++ Standard Baseline and Competitive Template Structure

## Status
Accepted

## Date
2026-11-07

## Context
Competitive programming platforms (Codeforces, UVA, LightOJ, SPOJ, LeetCode, AtCoder, HackerRank) employ differing compiler toolchains ranging from GCC 7 to GCC 14, supporting language revisions from C++11 to C++23.

Solutions must simultaneously satisfy strict criteria:
1. **Time Limits**: Execute within 1.0 to 2.0 seconds (~$10^8$ operations), requiring optimal asymptotic complexity and minimal runtime I/O overhead.
2. **Submission Constraints**: Online judges mandate single-file submissions without external third-party library dependencies.
3. **Memory Limits & Overflow**: Solutions frequently process cumulative sums and intermediate products up to $10^{18}$, which silently overflow 32-bit signed integers.
4. **Multi-Test Case Contamination**: Contests test dozens to hundreds of cases per execution; uncleared state in global arrays, adjacency lists, and dynamic programming tables causes subtle Presentation Error (PE) or Wrong Answer (WA) verdicts.

## Decision
We standardize the repository on **C++17** as the baseline compiler standard with full **C++20** forward compatibility, while enforcing strict contest template invariants:

1. **Compilation Standard & Toolchain**:
   - Baseline target: `-std=c++17`. Modern features such as structured bindings, `constexpr` `if`, `std::string_view`, fold expressions, and class template argument deduction (CTAD) are permitted and encouraged.
   - Forward compatibility: Local compilation and verification should target `-std=c++20` with `-O2` optimization and strict diagnostics (`-Wall -Wextra`).
   - Debugging builds: Must compile cleanly with AddressSanitizer and UndefinedBehaviorSanitizer (`-fsanitize=address,undefined -g`).

2. **Fast I/O & Stream Handling**:
   - Stream synchronization: Always include `ios_base::sync_with_stdio(false); cin.tie(NULL);` at the start of `main()`, or use the custom buffered integer reader `read(T &x)`.
   - Line endings: Never use `std::endl` in loops or frequent output; always use `'\n'` to avoid premature buffer flushes.

3. **Type Safety & Overflow Guardrails**:
   - Cumulative sums, combinatorial counters, factorials, modular arithmetic, and graph capacities must use `long long int` (`int64_t`).
   - Floating-point comparisons must use epsilon tolerance (`eps = 1e-9`).

4. **Multi-Test Case State Sanitization**:
   - For multi-test problems (`cin >> t; while (t--)`), all global data structures, vectors, frequency arrays, and DP memoization tables must be cleared (`memset` or `.clear()`) at the start of each test case iteration.

5. **Self-Contained File Architecture**:
   - Every algorithmic solution and template in `Online Judges/` and `Algorithms/` must remain completely self-contained, requiring zero external header includes beyond standard C++ library headers (`<iostream>`, `<vector>`, `<bits/stdc++.h>`).

## Alternatives Considered

### Retaining Legacy C++98 / C++11 as the Baseline
- *Pros*: Maximum legacy compatibility with obsolete contest environments.
- *Cons*: Deprives developers of modern, readable syntax (e.g., auto type deduction, structured bindings, lambdas, range-based loops). All target judges currently support at least C++17.
- *Rejected*: C++17 provides the optimal balance of modern ergonomics and universal judge support.

### Header-Only Modular Library Architecture
- *Pros*: Better software engineering separation of concerns.
- *Cons*: Judges require single-file submissions; requiring a build-time preprocessor or bundle step adds unnecessary friction during contest conditions.
- *Rejected*: Self-contained single-file templates and solutions are standard and required for competitive programming.

## Consequences
- All templates and accepted solutions conform to a uniform, high-performance C++17/C++20 standard.
- Unintentional state carryover between test cases is eliminated by convention.
- Solutions remain immediately copy-pasteable and verifiable across contemporary online judge platforms.
