# Number Theory Algorithms & Mathematical Foundations

Number Theory is essential in competitive programming for cryptography, combinatorics, modular arithmetic, and prime factorization.

---

## 1. Prime Sieves

### Sieve of Eratosthenes (`sieve-of-eratosthenes/Sieve alogorithm.cpp`)
Finds all prime numbers up to $N$.
1. Create a boolean array `isPrime[0...N]` initialized to `true`.
2. For $i = 2, 3, \dots, \lfloor \sqrt{N} \rfloor$:
   - If `isPrime[i]` is true, mark all multiples $i^2, i^2 + i, i^2 + 2i, \dots \le N$ as `false`.
- **Complexity:** $O(N \log \log N)$ time, $O(N)$ space.

### Bitwise Sieve (`Bitwise-sieve/source code.cpp`)
Stores prime flags using 32-bit integer bitmasks (`int status[N/32]`), reducing memory by a factor of 32!
- Can generate primes up to $10^8$ inside the standard 64 MB memory limit.
- Checks bit using `(status[x >> 5] & (1 << (x & 31)))`.

### Segmented Sieve (`segment_seive/seg_seive.cpp`)
Finds all primes in an interval $[L, R]$ where $R \le 10^{12}$ and $R - L \le 10^6$:
1. Precompute small primes up to $\lfloor \sqrt{R} \rfloor$ using standard sieve.
2. For each small prime $p$, mark its multiples in the range $[L, R]$:
   $$\text{FirstMultiple} = \max(p^2, \; \lceil L / p \rceil \cdot p)$$
- **Complexity:** $O((R - L + 1) \log \log R + \sqrt{R})$ time, $O(R - L + 1)$ space.

---

## 2. Greatest Common Divisor (GCD) & Extended Euclidean

### Euclidean Algorithm (`GCD-iterative/` & `GCD-using-recursion/`)
Based on the identity $\gcd(a, b) = \gcd(b, a \pmod b)$:
```cpp
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
```
- **Complexity:** $O(\log(\min(a, b)))$ (worst case occurs on consecutive Fibonacci numbers).

### Extended Euclidean Algorithm (`Extended-Euclidian-Algorithm/source code.cpp`)
Finds integer solutions $(x, y)$ to Bezout's identity:
$$a \cdot x + b \cdot y = \gcd(a, b)$$
- **Recursive Step:** If $b \cdot x_1 + (a \pmod b) \cdot y_1 = g$, then:
  $$x = y_1, \quad y = x_1 - \lfloor a / b \rfloor \cdot y_1$$
- **Complexity:** $O(\log(\min(a, b)))$ time.

---

## 3. Modular Arithmetic & Inverses

### Modular Multiplicative Inverse (`Moduler-inverse-using-Extended-Euclid/source code.cpp`)
The modular inverse $a^{-1} \pmod M$ satisfies $a \cdot a^{-1} \equiv 1 \pmod M$:
1. **When $M$ is prime (Fermat's Little Theorem):**
   $$a^{M - 1} \equiv 1 \pmod M \implies a^{-1} \equiv a^{M - 2} \pmod M$$
2. **When $M$ is not prime ($\gcd(a, M) == 1$):**
   Use Extended Euclidean: $a \cdot x + M \cdot y = 1 \implies a \cdot x \equiv 1 \pmod M$. The inverse is $(x \pmod M + M) \pmod M$.
- **Complexity:** $O(\log M)$ time.

### Fast Modular Exponentiation (`Moduler-Exponential/` & `Moduler-Exponential-using-bit/`)
Computes $(a^b) \pmod M$ in $O(\log b)$ by squaring the base and halving the exponent:
```cpp
long long bigmod(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
```

### Binary Multiplication / `mulmod` (`Big multiply/bm.cpp`)
Computes $(a \cdot b) \pmod M$ when $a \cdot b$ would overflow 64-bit `unsigned long long` integers (up to $10^{18}$):
Uses repeated doubling and addition in $O(\log b)$ time.

---

## 4. Primality Testing & Factorization

### Miller-Rabin Primality Test (`miller robin prime check.cpp`)
Deterministic primality test for 64-bit numbers:
Write $N - 1 = 2^s \cdot d$. For each test base $a$:
- Compute $x = a^d \pmod N$.
- If $x == 1$ or $x == N - 1$, continue to next base.
- Repeat squaring $x = x^2 \pmod N$ up to $s - 1$ times. If $x == N - 1$, continue.
- If neither holds, $N$ is **composite**.
- Testing bases $\{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37\}$ deterministically tests any $N < 2^{64}$.
- **Complexity:** $O(K \log^2 N)$ time.

### Euler's Totient Function $\phi(N)$ (`Euler-PI-function-to-determine-relative-prime/`)
Counts positive integers $\le N$ that are coprime to $N$.
From the prime factorization $N = p_1^{a_1} p_2^{a_2} \dots p_k^{a_k}$:
$$\phi(N) = N \prod_{i=1}^k \left( 1 - \frac{1}{p_i} \right)$$
- **Complexity:** $O(\sqrt{N})$ for a single query; $O(N \log \log N)$ to precompute for all $1 \dots N$ via sieve.

### Number and Sum of Divisors (`No-Of-Divisors/no_of_div.cpp`)
For $N = p_1^{a_1} p_2^{a_2} \dots p_k^{a_k}$:
- **Number of Divisors $d(N)$:**
  $$d(N) = \prod_{i=1}^k (a_i + 1)$$
- **Sum of Divisors $\sigma(N)$:**
  $$\sigma(N) = \prod_{i=1}^k \frac{p_i^{a_i + 1} - 1}{p_i - 1}$$

---

## 5. Advanced Theorems

### Legendre's Formula (`number_of_factors_in_factorial.cpp`)
Finds the exponent of prime $P$ in the prime factorization of $N!$:
$$E_P(N!) = \sum_{k=1}^{\infty} \left\lfloor \frac{N}{P^k} \right\rfloor = \left\lfloor \frac{N}{P} \right\rfloor + \left\lfloor \frac{N}{P^2} \right\rfloor + \left\lfloor \frac{N}{P^3} \right\rfloor + \dots$$
- **Complexity:** $O(\log_P N)$ time, $O(1)$ space.

### Lucas' Theorem (`locus ncr in mlogn.cpp`)
Computes $\binom{N}{R} \pmod P$ when $N, R$ are huge ($N, R \le 10^{18}$) and prime $P$ is small ($P \le 10^5$):
Express $N$ and $R$ in base $P$:
$$N = n_k P^k + \dots + n_1 P + n_0, \quad R = r_k P^k + \dots + r_1 P + r_0$$
Then:
$$\binom{N}{R} \equiv \prod_{i=0}^k \binom{n_i}{r_i} \pmod P$$
where $\binom{n_i}{r_i} = 0$ if $n_i < r_i$.
- **Complexity:** $O(P + \log_P N)$ time.
