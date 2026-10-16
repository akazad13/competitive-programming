/**
 * @file number_of_factors_in_factorial.cpp
 * @brief Legendre's Formula - Multiplicity of prime p in n!
 * 
 * Computes the highest power of a prime p dividing n! (factorial),
 * using Legendre's Formula:
 *   E_p(n!) = sum_{k=1}^inf floor(n / p^k)
 * 
 * Time Complexity:  O(log_p(n))
 * Space Complexity: O(1)
 */

#include <iostream>

using namespace std;

typedef long long ll;

// Returns the exponent of prime p in prime factorization of n!
ll get_pow(ll n, ll p) {
    ll res = 0;
    for (ll pow = p; pow <= n; pow *= p) {
        res += (n / pow);
    }
    return res;
}

int main() {
    ll n, p;
    cout << "Enter n and prime p: ";
    if (cin >> n >> p) {
        cout << "Highest power of " << p << " dividing " << n << "! is: " 
             << get_pow(n, p) << "\n";
    }
    return 0;
}
