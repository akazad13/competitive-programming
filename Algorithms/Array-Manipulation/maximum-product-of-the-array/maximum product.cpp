/**
 * @file maximum product.cpp
 * @brief Maximum Product Subarray
 * 
 * Computes the maximum product of a contiguous subarray in an array of integers.
 * Uses two passes (forward and backward) to handle negative numbers and zeroes.
 * 
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

ll max_product(const vector<ll> &arr, int n) {
    if (n == 0) return 0;
    ll max_fwd = LLONG_MIN, max_bkd = LLONG_MIN;
    ll max_till_now = 1;

    for (int i = 0; i < n; i++) {
        max_till_now = max_till_now * arr[i];
        if (max_till_now == 0) {
            max_till_now = 1;
            continue;
        }
        if (max_fwd < max_till_now)
            max_fwd = max_till_now;
    }

    max_till_now = 1;
    for (int i = n - 1; i >= 0; i--) {
        max_till_now = max_till_now * arr[i];
        if (max_till_now == 0) {
            max_till_now = 1;
            continue;
        }
        if (max_bkd < max_till_now)
            max_bkd = max_till_now;
    }

    ll res = max(max_fwd, max_bkd);
    return res;
}

int main() {
    int n;
    if (cin >> n) {
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << max_product(arr, n) << "\n";
    }
    return 0;
}
