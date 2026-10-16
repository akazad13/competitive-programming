# Mathematics & Number Theory for Competitive Programming

This directory contains implementations of mathematical and number-theoretic algorithms:

## 1. Big Number Arithmetic (`Big-Number-Arithemetic/`)

| Algorithm / Operation | File | Description | Complexity |
|---|---|---|---|
| **BigInt Multiplication** | `string-or-vector and a number multyply.cpp` | Multiplies arbitrary-precision BigInt by standard integer | $O(D)$ |
| **BigInt Add, Sub, Div** | `add-substract-divide/add substract divide.cpp` | Addition, subtraction, and division by 2 on large numbers | $O(D)$ |

## 2. Number Theory (`Number-Theory/`)

| Algorithm / Technique | File / Directory | Description | Complexity |
|---|---|---|---|
| **Sieve of Eratosthenes** | `sieve-of-eratosthenes/Sieve alogorithm.cpp` | Prime generation up to $N$ | $O(N \log \log N)$ |
| **Bitwise Sieve** | `Bitwise-sieve/source code.cpp` | Memory-optimized prime sieve using bitwise operators | $O(N \log \log N)$ time, $O(N / 32)$ space |
| **Segmented Sieve** | `segment_seive/seg_seive.cpp` | Generates primes in a range $[L, R]$ | $O((R - L + 1) \log \log R + \sqrt{R})$ |
| **Greatest Common Divisor (GCD)** | `GCD-iterative/GCD iterative.cpp` | Iterative Euclidean algorithm for $\gcd(a, b)$ | $O(\log(\min(a, b)))$ |
| **Recursive GCD** | `GCD-using-recursion/source code.cpp` | Recursive Euclidean algorithm | $O(\log(\min(a, b)))$ |
| **Extended Euclidean Algorithm** | `Extended-Euclidian-Algorithm/source code.cpp` | Solves $a \cdot x + b \cdot y = \gcd(a, b)$ for Bezout coefficients | $O(\log(\min(a, b)))$ |
| **Modular Inverse** | `Moduler-inverse-using-Extended-Euclid/source code.cpp` | Multiplicative inverse $a^{-1} \pmod M$ | $O(\log M)$ |
| **Modular Exponentiation** | `Moduler-Exponential/source code.cpp` | Computes $(a^b) \pmod M$ via binary exponentiation | $O(\log b)$ |
| **Modular Exponentiation (Bitwise)** | `Moduler-Exponential-using-bit/ME using bit.cpp` | Fast bit-shift modular exponentiation | $O(\log b)$ |
| **Binary Modular Multiplication** | `Big multiply/bm.cpp` | $(a \cdot b) \pmod M$ without 64-bit overflow | $O(\log b)$ |
| **Miller-Rabin Primality Test** | `miller robin prime check.cpp` | Deterministic/probabilistic 64-bit prime test | $O(K \log^2 N)$ |
| **Euler's Totient ($\phi$) Function** | `Euler-PI-function-to-determine-relative-prime/` | Counts numbers $\le N$ coprime to $N$ | $O(\sqrt{N})$ |
| **Number & Sum of Divisors** | `No-Of-Divisors/no_of_div.cpp` | Calculates $d(n)$ and $\sigma(n)$ via prime factors | $O(\sqrt{N})$ |
| **Legendre's Formula** | `number_of_factors_in_factorial.cpp` | Multiplicity of prime $P$ in $N!$ | $O(\log_P N)$ |
| **Lucas' Theorem** | `locus ncr in mlogn.cpp` | $n\text{C}r \pmod P$ for large $n, r$ with small prime $P$ | $O(P + \log_P n)$ |
| **Large Fibonacci** | `fibonacci-Number/Nth Fibonacci Number when N is BIG.cpp` | Fast doubling method / matrix exponentiation for $F_N$ | $O(\log N)$ |
