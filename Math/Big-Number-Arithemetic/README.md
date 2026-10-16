# Arbitrary-Precision Arithmetic (BigInt)

Competitive programming languages like C++ lack native arbitrarily large integer types (unlike Python's unbounded integers or Java's `BigInteger`). When calculations exceed the 64-bit integer limit ($2^{63} - 1 \approx 9.22 \times 10^{18}$), custom Big Integer arithmetic is required.

---

## 1. Internal Representation

A BigInt is represented as a sequence of base-10 digits stored in a `std::vector<int>` or `std::string` in **little-endian** order (least significant digit at index 0):
```
Number: 12345
Vector: [5, 4, 3, 2, 1]
Index:   0  1  2  3  4
```
- **Why Little-Endian?** Adding new higher-order digits when carrying requires only an $O(1)$ `push_back()`, avoiding $O(N)$ front-insertions.

---

## 2. Operations & Implementations

### A. BigInt Addition (`add-substract-divide/add substract divide.cpp`)
Simulates schoolbook column addition with a carry:
```cpp
vector<int> add(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % 10);
        carry /= 10;
    }
    return c;
}
```
- **Time Complexity:** $O(\max(D_a, D_b))$.
- **Space Complexity:** $O(\max(D_a, D_b))$.

### B. BigInt Subtraction (`add-substract-divide/add substract divide.cpp`)
Assumes $A \ge B$. Simulates column subtraction borrowing from higher digits:
```cpp
vector<int> subtract(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    int borrow = 0;
    for (size_t i = 0; i < a.size(); i++) {
        int diff = a[i] - borrow - (i < b.size() ? b[i] : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        c.push_back(diff);
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back(); // Trim leading zeros
    return c;
}
```
- **Time Complexity:** $O(D_a)$.

### C. BigInt Division by 2 (`add-substract-divide/add substract divide.cpp`)
Traverses digits from most significant to least significant, carrying remainders:
```cpp
vector<int> divide_by_2(const vector<int> &a) {
    vector<int> c(a.size());
    int rem = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int cur = rem * 10 + a[i];
        c[i] = cur / 2;
        rem = cur % 2;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
```
- **Time Complexity:** $O(D)$.

### D. BigInt $\times$ Standard Integer (`string-or-vector and a number multyply.cpp`)
Multiplies BigInt array by a standard 64-bit integer $M$ (frequently used for computing factorials $N!$ up to $N = 1000$):
```cpp
void multiply(vector<int> &res, long long n) {
    long long carry = 0;
    for (size_t i = 0; i < res.size(); i++) {
        carry += (long long)res[i] * n;
        res[i] = carry % 10;
        carry /= 10;
    }
    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
}
```
- **Time Complexity:** $O(D + \log_{10} M)$.
