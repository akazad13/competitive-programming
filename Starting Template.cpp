/**
 * @file Starting Template.cpp
 * @brief Competitive Programming Template in C++
 * @author akazad13
 * 
 * Includes common headers, I/O optimizations, fast read routines,
 * bit-manipulation helpers, basic math functions (GCD, BigMod, ModInverse, Extended Euclidean),
 * and geometry distance helpers.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, p, n) for (i = p; i < n; i++)
#define ll long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int, int>
#define mp(a, b) make_pair(a, b)
#define eps 1e-9
#define PI (2.0 * acos(0.0))
#define SQR(x) ((x) * (x))

ll MOD = 1000000007;
#define INF (1 << 28)

#define Clear(a, b) memset(a, b, sizeof(a))

// Fast integer input template
template<class T> inline bool read(T &x) {
    int c = getchar();
    int sgn = 1;
    while ((c < '0' || c > '9') && c != '-' && c != EOF) {
        c = getchar();
    }
    if (c == EOF) return false;
    if (c == '-') {
        sgn = -1;
        c = getchar();
    }
    for (x = 0; c >= '0' && c <= '9'; c = getchar()) {
        x = x * 10 + c - '0';
    }
    x *= sgn;
    return true;
}

// Modular Exponentiation: (p^e) % M - O(log e)
template <class T> inline T bigmod(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)(ret % M);
}

// Greatest Common Divisor - O(log(min(a, b)))
template <class T> inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Modular Multiplicative Inverse (when M is prime) using Fermat's Little Theorem - O(log M)
template <class T> inline T modinverse(T a, T M) {
    return bigmod(a, M - 2, M);
}

// Fast Power - O(log P)
template<typename T> inline T POW(T B, T P) {
    if (P == 0) return 1;
    if (P & 1) return B * POW(B, P - 1);
    else return SQR(POW(B, P / 2));
}

// Euclidean 2D Distance
template<typename T> inline T Dis(T x1, T y1, T x2, T y2) {
    return sqrt(SQR(x1 - x2) + SQR(y1 - y2));
}

// Angle calculation
template<typename T> inline T Angle(T x1, T y1, T x2, T y2) {
    return atan(double(y1 - y2) / double(x1 - x2));
}

template<typename T> inline T DIFF(T a, T b) {
    T d = a - b;
    return (d < 0) ? -d : d;
}

template<typename T> inline T ABS(T a) {
    return (a < 0) ? -a : a;
}

// Extended Euclidean Algorithm: a*x + b*y = gcd(a, b)
template<typename T> inline T euclide(T a, T b, T &x, T &y) {
    if (a < 0) {
        T d = euclide(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = euclide(a, -b, x, y);
        y = -y;
        return d;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = euclide(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}

// Bit manipulation utilities
inline int Set(int N, int pos) {
    return N = N | (1 << pos);
}

inline int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}

inline bool check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

/************************************************************************************/

int main() {
    // Fast I/O (uncomment if using cin/cout)
    // ios_base::sync_with_stdio(false); cin.tie(NULL);

    // File I/O (uncomment for file testing)
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int test, Case;
    if (read(test)) {
        for (Case = 1; Case <= test; Case++) {
            // Write your solution here
        }
    }

    return 0;
}
