# Architecture Decision Records (ADRs)

This directory documents the technical and architectural decisions for the [`akazad13/competitive-programming`](https://github.com/akazad13/competitive-programming) repository.

We adhere to the Architecture Decision Record methodology per the repository's documentation standards to maintain clear technical rationale, invariants, and trade-offs for developers and autonomous AI agents.

## ADR Lifecycle

```text
PROPOSED ──► ACCEPTED ──► (SUPERSEDED by ADR-XXXX | DEPRECATED)
```

Historical ADRs are retained permanently to capture context and decision rationales.

---

## Index of Decisions

| ADR | Title | Status | Date | Summary |
| :---: | :--- | :---: | :---: | :--- |
| [0001](0001-record-architecture-decisions.md) | **Record Architecture Decisions** | `Accepted` | 2026-11-07 | Adopt ADR methodology to track architectural choices, template conventions, and technical trade-offs. |
| [0002](0002-cpp-standard-and-template-structure.md) | **C++ Standard Baseline and Competitive Template Structure** | `Accepted` | 2026-11-07 | Standardize on C++17/C++20 baseline, fast I/O invariants, 64-bit integer safety, and self-contained solution files. |
| [0003](0003-testing-paradigm-and-agentic-verification.md) | **Testing Paradigm and Agentic Verification** | `Accepted` | 2026-11-07 | Codify I/O redirection testing, edge-case stress suites, multi-test state isolation, and automated pre-submission verification. |
