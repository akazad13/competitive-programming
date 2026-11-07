# ADR-0001: Record Architecture Decisions

## Status
Accepted

## Date
2026-11-07

## Context
The `competitive-programming` repository contains an extensive collection of data structures, algorithms, mathematical modules, contest templates, and over 560 accepted online judge solutions. Competitive programming codebases frequently evolve through iterative additions under contest time constraints.

Without explicit architectural records:
- The rationale behind technical choices (e.g., C++ standard baseline, fast I/O mechanisms, global buffer sizing vs. dynamic allocation, test case sanitization idioms) is easily lost or obscured.
- Contributors and autonomous AI agents risk introducing inconsistent idioms, redundant implementations, or regressions across online judges.
- Invariants critical to passing online judge constraints (time limits, memory limits, undefined behavior prevention) may be compromised without a documented contract.

## Decision
We adopt Architecture Decision Records (ADRs) to document significant architectural, technical, and convention decisions across the repository.

1. **Format and Location**:
   - ADRs are stored as Markdown documents in `docs/adr/`.
   - Files are numbered sequentially with four digits followed by a hyphenated slug: `XXXX-title.md` (e.g., `0001-record-architecture-decisions.md`).
   - Every ADR must include:
     - Title (`# ADR-XXXX: Title`)
     - Status (`Proposed`, `Accepted`, `Superseded by ADR-YYYY`, or `Deprecated`)
     - Date (`YYYY-MM-DD`)
     - Context
     - Decision
     - Alternatives Considered
     - Consequences

2. **Index**:
   - An index file (`docs/adr/README.md`) catalogs all ADRs in tabular form with status, date, and summary links.

3. **Lifecycle**:
   - Old decisions are never deleted; when conventions change, a new ADR is authored that explicitly references and supersedes the preceding ADR.

## Alternatives Considered

### Ad-hoc Code Comments and Commit Logs
- *Pros*: Zero file maintenance overhead.
- *Cons*: Crucial rationale is scattered across hundreds of files or buried in commit history; difficult for developers and AI agents to discover, audit, and reason about systematically.
- *Rejected*: Inadequate for long-term repository governance and cross-judge consistency.

### Heavyweight Architecture Frameworks
- *Pros*: Rigorous enterprise modeling.
- *Cons*: Overly complex for a competitive programming and algorithmic repository.
- *Rejected*: Unnecessary friction; lightweight Markdown ADRs fit our git-centric workflow cleanly.

## Consequences
- Every significant technical choice, language feature adoption, and structural paradigm will have a discoverable *why*.
- Contributors and autonomous agents must consult `docs/adr/` before introducing broad structural changes or altering core template invariants.
- Decisions can be referenced in code comments, commit messages, and agent instructions (e.g., `AGENTS.md`).
