/**
 * @file string-or-vector and a number multyply.cpp
 * @brief Arbitrary-Precision Multiplication (BigInt * standard integer)
 * 
 * Multiplies a large number stored in a std::vector<int> (digits in reverse order)
 * by a standard 64-bit integer n.
 * 
 * Time Complexity:  O(D + log10(carry)) where D is number of digits
 * Space Complexity: O(D)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Multiplies BigInt `res` (least significant digit at index 0) by integer `n`
void multiply(vector<int> &res, long long int n) {
    int SIZE = res.size();
    long long int carry = 0;
    for (int i = 0; i < SIZE; i++) {
        carry += res[i] * n;
        res[i] = carry % 10;
        carry /= 10;
    }
    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
}

int main() {
    // Example: Compute factorial of N using BigInt multiplication
    int n;
    while (cin >> n && n >= 0) {
        vector<int> res = {1};
        for (int i = 2; i <= n; i++) {
            multiply(res, i);
        }
        cout << n << "! = ";
        for (int i = (int)res.size() - 1; i >= 0; i--) {
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}
