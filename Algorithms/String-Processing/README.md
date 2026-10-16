# String Processing Algorithms & Pattern Matching

String algorithms form a crucial cornerstone of competitive programming, enabling fast substring searches, cyclic equivalence tests, and prefix-based queries.

---

## 1. Knuth-Morris-Pratt (KMP) Algorithm (`KMP/kmp.cpp`)

### Concept & Intuition
Searches for occurrences of pattern $P$ of length $M$ in text $T$ of length $N$. When a mismatch occurs, instead of backtracking the text pointer, KMP uses the **Prefix Function** ($\pi$ table) to skip redundant comparisons.

### Prefix Function ($\pi$)
$\pi[i]$ is defined as the length of the longest proper prefix of $P[0 \dots i]$ that is also a suffix of $P[0 \dots i]$:
$$\pi[i] = \max \{ k : 0 \le k < i \land P[0 \dots k - 1] = P[i - k + 1 \dots i] \}$$

### Computation & Search
- **Preprocessing $\pi$:** Built in $O(M)$ time using two pointers.
- **Matching:** Advance pointer $j$ in pattern. On mismatch $T[i] \ne P[j]$, fallback to $j = \pi[j - 1]$ until a match or $j == 0$.
- **Complexity:** $O(N + M)$ time, $O(M)$ auxiliary space.

---

## 2. Z-Algorithm (`Z algorithm/Z.cpp`)

### Concept & Intuition
Given a string $S$ of length $N$, the Z-array stores in $Z[i]$ the length of the longest common prefix (LCP) between $S$ and the suffix of $S$ starting at index $i$:
$$Z[i] = \max \{ k : S[0 \dots k - 1] = S[i \dots i + k - 1] \}$$

### Mechanism (The Z-Box $[L, R]$)
Maintains an interval $[L, R]$ which is the prefix-matching segment with the largest $R$ discovered so far:
1. If current index $i > R$, compute $Z[i]$ by naive character comparisons starting at $i$, and update $L = i, R = i + Z[i] - 1$.
2. If $i \le R$, let $k = i - L$. The substring $S[i \dots R]$ matches $S[k \dots R - L]$:
   - If $Z[k] < R - i + 1$, then $Z[i] = Z[k]$ directly!
   - If $Z[k] \ge R - i + 1$, then $Z[i]$ is at least $R - i + 1$. Continue matching naively past $R$ and update $[L, R]$.
- **Pattern Matching:** Construct string $S = P + \text{"#"} + T$. Any index where $Z[i] == |P|$ represents an exact occurrence of $P$ in $T$.
- **Complexity:** $O(N)$ time, $O(N)$ space.

---

## 3. Rabin-Karp Rolling Hash (`Robin Karp Hash/RK.cpp`)

### Concept
Maps strings into integers using a polynomial rolling hash function:
$$\text{Hash}(S) = \left( \sum_{i=0}^{N-1} S[i] \cdot B^{N - 1 - i} \right) \pmod M$$
where $B$ is a base (e.g. 31 or 53) and $M$ is a large prime (e.g. $10^9 + 7$).

### $O(1)$ Window Rolling
Moving the hash window of length $L$ from index $i$ to $i + 1$:
$$\text{Hash}(S[i+1 \dots i+L]) = \Big( (\text{Hash}(S[i \dots i+L-1]) - S[i] \cdot B^{L-1}) \cdot B + S[i+L] \Big) \pmod M$$
- **Double Hashing:** To completely prevent hash collisions (anti-hash test cases in contests), use two independent pairs of $(B_1, M_1)$ and $(B_2, M_2)$ or `__int128` with modulo $2^{61} - 1$.
- **Complexity:** $O(N + M)$ average time, $O(1)$ space.

---

## 4. Trie (Prefix Tree) (`Trie/`)

### Structure & Purpose
An ordered retrieval tree data structure where each node represents a character along string prefixes.
- **Array-Based Trie (`Trie array.cpp`):**
  Uses static arrays `trie[MAX_NODES][ALPHABET_SIZE]` and `isEnd[MAX_NODES]`. Fast and cache-friendly; standard for competitive programming when maximum total characters is known.
- **Pointer-Based Trie (`trie link list.cpp`):**
  Uses dynamic heap allocation `struct Node* next[26]`. Flexible for variable-sized inputs and sparse alphabets.
- **Complexity:**
  - Insertion: $O(L)$ where $L$ is string length.
  - Search / Prefix Query: $O(L)$.
  - Space Complexity: $O(N \cdot L \cdot \Sigma)$ where $\Sigma$ is alphabet size.

---

## 5. Longest Common Subsequence (LCS) (`Longest-Common-Subsequence/LCS.cpp`)

### Recurrence
For two strings $S_1$ and $S_2$:
$$\text{dp}[i][j] = \begin{cases} 
1 + \text{dp}[i - 1][j - 1] & \text{if } S_1[i - 1] == S_2[j - 1] \\
\max(\text{dp}[i - 1][j], \; \text{dp}[i][j - 1]) & \text{if } S_1[i - 1] \ne S_2[j - 1]
\end{cases}$$

### String Reconstruction
Trace back from $(|S_1|, |S_2|)$ following cell transitions to output the actual subsequence.
- **Complexity:** $O(|S_1| \cdot |S_2|)$ time and space.

---

## 6. Lexicographically Smallest String Rotation (`rotating lexi sortest/raot.cpp`)

### Problem
Given a string $S$ of length $N$, find the starting index $i$ such that the cyclic rotation $S[i \dots N-1] + S[0 \dots i-1]$ is lexicographically smallest.

### Booth's Algorithm
Construct $S' = S + S$. Maintain candidate pointers $i$ and $j$, and match count $k$:
- If $S'[i + k] == S'[j + k]$, increment $k$.
- If $S'[i + k] > S'[j + k]$, the rotation at $i$ is strictly worse. Jump $i = i + k + 1$ (if $i \le j$, set $i = j + 1$) and reset $k = 0$.
- Else, jump $j = j + k + 1$ (if $j \le i$, set $j = i + 1$) and reset $k = 0$.
- **Complexity:** $O(N)$ linear time and space, far superior to sorting all $N$ rotations in $O(N^2 \log N)$.
