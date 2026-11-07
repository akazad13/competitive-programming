# ADR-0003: Testing Paradigm and Agentic Verification

## Status
Accepted

## Date
2026-11-07

## Context
In competitive programming, solutions are evaluated by black-box automated judge systems with strict correctness, time limit (typically 1.0 to 2.0 seconds), memory limit (typically 64 MB to 512 MB), and formatting constraints. Unlike traditional enterprise software with unit test frameworks (e.g., Google Test, Catch2), competitive programming solutions must remain self-contained single-file sources that interact exclusively through standard streams (`std::cin`, `std::cout`, or `read()`).

Autonomous AI coding agents frequently introduce preventable submission failures:
1. **Formatting and Presentation Errors (PE/WA)**: Extra or missing whitespace, trailing line breaks, or mismatched case identifiers (e.g., `Case 1:` vs `Case #1:`).
2. **Multi-Test Case State Contamination**: Uncleared global arrays, graphs, or dynamic programming memoization tables between successive test cases, where a solution passes isolated tests but fails when evaluated in batches (`while (t--)`).
3. **Integer Overflow & Truncation**: 32-bit signed arithmetic overflow during cumulative sums, factorials, coordinate distances, or modular arithmetic leading to silent errors.
4. **Boundary and Corner Case Failures**: Degenerate bounds ($N=0, 1$, negative coordinates, empty strings, disconnected topologies, maximum $N=10^5$ stress limits) triggering runtime errors (SIGSEGV/SIGFPE) or Time Limit Exceeded (TLE).
5. **Flawed "Looks Right" Heuristics**: Submitting without verified local execution against sample input and known stress scenarios.

A formal testing paradigm grounded in Test-Driven Development (TDD) principles is required to guarantee agentic code quality and zero-regression verification.

## Decision
We establish the **Competitive Programming Testing Paradigm for Agentic Development**, enforcing automated I/O redirection, multi-test state isolation, edge-case stress suites, and sanitizer-backed verification prior to submission or code integration:

### 1. Competitive TDD Cycle (Sample-First Verification)
Every solution implementation or algorithmic refinement by an agent must follow the adapted Red-Green-Refactor cycle:
- **RED (Assert Expectation)**: Before authoring the core algorithm, capture sample inputs and official sample outputs in local test fixtures (e.g., `input.txt` and `expected.txt`, or inline heredocs). Running the initial solution against sample input must fail or demonstrate incomplete state.
- **GREEN (Pass Samples)**: Author the minimum asymptotically sound algorithm that transforms the input to the exact expected output without runtime warnings.
- **REFACTOR (Harden & Optimize)**: Refactor code for optimal time and space complexity, remove exploratory debug statements, and ensure C++17/C++20 idioms without altering I/O behavior.

### 2. Standard I/O Redirection Testing
Verification must be executed via standard stream redirection to mirror online judge grading environments:
```bash
# 1. Compile with C++20, optimization, and strict warnings
g++ -std=c++20 -O2 -Wall -Wextra solution.cpp -o solution

# 2. Execute with stream redirection
./solution < input.txt > output.txt

# 3. Assert exact byte/whitespace equivalence
diff -u output.txt expected.txt
```
For Windows PowerShell environments where diff utilities vary:
```powershell
Get-Content input.txt | ./solution.exe | Set-Content output.txt
Compare-Object (Get-Content output.txt) (Get-Content expected.txt)
```

### 3. Inviolable Verification Invariants
- **Exact Whitespace and Format Matching**: Output must match official problem specifications exactly. Trailing spaces, missing newlines between test cases, or discrepancies in case headers (`Case X:`) are treated as test failures.
- **Sub-Second Execution Limits**: Local execution on maximum input bounds ($N = 10^5$ to $10^6$) must execute well within typical judge limits (sub-second target $< 1.0\text{s}$) with fast I/O enabled (`ios_base::sync_with_stdio(false); cin.tie(NULL);` or `read()`).
- **Deterministic Multi-Test Case Isolation**: Every multi-test case solution must pass duplicate consecutive execution tests. If input case $A$ is repeated consecutively ($t=2$ with identical payload $A$), the output for both cases must be strictly identical. All global buffers, adjacency lists, and DP tables must be explicitly re-initialized at the start of each test case.
- **Sanitizer Verification (ASan & UBSan)**: When diagnosing segfaults, out-of-bounds array accesses, or integer overflows, code must be compiled with `-fsanitize=address,undefined -g` and verified against sample and boundary cases.

### 4. Mandatory Edge Case & Stress Testing Suite
Before declaring any solution verified, agents must evaluate the following test matrix:
1. **Minimum Bounds**: $N = 0$, $N = 1$, empty arrays, trees with 1 vertex, graphs with 0 edges.
2. **Maximum Bounds**: $N = \max(N)$, $K = \max(K)$ to verify no memory limit exceeded (MLE) or asymptotic time regressions (TLE).
3. **64-bit Integer Overflow**: Values up to $10^9$ or $10^{18}$ tested against accumulation routines to ensure `long long` (`int64_t`) usage.
4. **Degenerate Topologies**: Skewed/line trees for graph algorithms, duplicate array elements, all-negative values for subarray problems.

## Alternatives Considered

### External Unit Testing Frameworks (Google Test, Catch2, doctest)
- *Pros*: Rich assertions, test discovery, structured failure reports.
- *Cons*: Introduces heavy external dependencies, multi-file linking, and incompatibility with single-file judge upload requirements.
- *Rejected*: Incompatible with zero-dependency competitive programming constraints.

### Pure Brute-Force Differential Fuzzing for All Problems
- *Pros*: Generates thousands of randomized test cases comparing fast solution against slow $O(N^2)$ brute-force.
- *Cons*: High overhead for standard competitive solutions; unnecessary for well-bounded textbook problems.
- *Adopted as Optional*: Recommended for complex contest problems (e.g., advanced Segment Trees or HLD), while sample I/O redirection + edge-case suite remains the mandatory baseline.

### Manual Visual Inspection ("Seems Right")
- *Pros*: Zero tool execution time.
- *Cons*: High error rate; fails to detect multi-test carryover, trailing whitespace issues, and 64-bit overflow.
- *Rejected*: Violates the core tenets of the TDD skill and agent verification standards.

## Consequences
- Every solution developed or updated by an AI agent is backed by verifiable sample and stress test inputs.
- Presentation errors and multi-test state contamination are caught before submission.
- The repository maintains high algorithmic integrity across its 560+ problem corpus.
