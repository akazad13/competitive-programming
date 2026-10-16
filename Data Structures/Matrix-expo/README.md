# Matrix Exponentiation for Competitive Programming

Matrix Exponentiation is a powerful technique for computing the $N$-th term of linear recurrence relations in $O(K^3 \log N)$ time, where $K$ is the order of the recurrence and $N$ can be as large as $10^{18}$.

---

## 1. Linear Recurrence to Matrix Form

### The Fibonacci Example
The Fibonacci sequence is defined by:
$$F_n = F_{n-1} + F_{n-2}, \quad F_0 = 0, \; F_1 = 1$$
We can express this in matrix form:
$$\begin{pmatrix} F_{n} \\ F_{n-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_{n-1} \\ F_{n-2} \end{pmatrix}$$
Repeatedly substituting yields:
$$\begin{pmatrix} F_{n} \\ F_{n-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^{n-1} \begin{pmatrix} F_1 \\ F_0 \end{pmatrix}$$

By computing $T^{n-1}$ via binary exponentiation in $O(\log n)$ matrix multiplications, $F_n$ is obtained in logarithmic time!

---

## 2. General Transformation Recipe

Given any linear recurrence of degree $K$:
$$A_n = c_1 A_{n-1} + c_2 A_{n-2} + \dots + c_k A_{n-k}$$
1. Construct state vector $V_n = \begin{bmatrix} A_n & A_{n-1} & \dots & A_{n-k+1} \end{bmatrix}^T$.
2. Construct the $K \times K$ transition matrix $M$:
   $$M = \begin{pmatrix}
   c_1 & c_2 & c_3 & \dots & c_k \\
   1 & 0 & 0 & \dots & 0 \\
   0 & 1 & 0 & \dots & 0 \\
   \vdots & \vdots & \ddots & \dots & 0 \\
   0 & 0 & \dots & 1 & 0
   \end{pmatrix}$$
3. $V_n = M^{n - k} \cdot V_k$.

---

## 3. Implementations in this Directory

- `template.cpp`: General $K \times K$ matrix multiplication and binary exponentiation template using modular arithmetic.
- `memory efficient.cpp`: Space-optimized in-place $2 \times 2$ matrix multiplication without dynamic heap allocation for fast competitive execution.
