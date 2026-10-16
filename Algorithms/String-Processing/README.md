# String Processing Algorithms

This directory contains implementations of classic string algorithms and data structures commonly used in competitive programming:

| Algorithm / Technique | Subdirectory / File | Description | Time Complexity |
|---|---|---|---|
| **KMP (Knuth-Morris-Pratt)** | `KMP/kmp.cpp` | Pattern matching with prefix function (pi table) | $O(N + M)$ |
| **Z-Algorithm** | `Z algorithm/Z.cpp` | Computes longest common prefix of string with its suffixes | $O(N)$ |
| **Rabin-Karp Hashing** | `Robin Karp Hash/RK.cpp` | Rolling polynomial hash for substring search | $O(N + M)$ avg |
| **Trie (Array-based)** | `Trie/Trie array.cpp` | Fast prefix tree using static arrays | $O(L)$ per op |
| **Trie (Linked List / Pointer)** | `Trie/trie link list.cpp` | Dynamic pointer-based prefix tree | $O(L)$ per op |
| **Longest Common Subsequence** | `Longest-Common-Subsequence/` | DP approach to find LCS of two strings | $O(N \cdot M)$ |
| **Palindrome Checking** | `Palindrome-checking/` | Fast palindrome verification & checks | $O(N)$ |
| **Lexicographically Smallest Rotation** | `rotating lexi sortest/raot.cpp` | Finds the minimal cyclic shift of a string (Booth's/Duval's idea) | $O(N)$ |
| **Char to String Conversion** | `input-char-to-string/` | Parsing and character manipulation helpers | $O(N)$ |
