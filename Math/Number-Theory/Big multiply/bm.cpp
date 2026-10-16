/**
 * @file bm.cpp
 * @brief Binary Modular Multiplication (mulmod: (a * b) % m without 64-bit overflow)
 * 
 * Computes (a * b) % m using binary exponentiation logic (Russian Peasant method)
 * to avoid 64-bit integer multiplication overflow when a, b, m are up to 10^18.
 * 
 * Time Complexity:  O(log b)
 * Space Complexity: O(1)
 */

#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll mulmod(ll a, ll b, ll c) {
    ll x = 0, y = a % c;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

int main() {
    ll a, b, m;
    while (cin >> a >> b >> m) {
        cout << "(" << a << " * " << b << ") % " << m << " = " << mulmod(a, b, m) << "\n";
    }
    return 0;
}
