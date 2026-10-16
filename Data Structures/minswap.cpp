/**
 * @file minswap.cpp
 * @brief Minimum Swaps to Sort an Array
 * 
 * Computes the minimum number of swaps required to sort an array
 * by finding cycles in the permutation graph.
 * For each cycle of length L, (L - 1) swaps are required.
 * 
 * Time Complexity:  O(n log n) due to sorting
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int

ll n;

ll minSwaps(const vector<ll> &arr) {
    vector<pair<ll, int>> arrPos(n);
    for (int i = 0; i < n; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos.begin(), arrPos.end());

    vector<bool> vis(n, false);
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] || arrPos[i].second == i)
            continue;

        ll cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = arrPos[j].second;
            cycle_size++;
        }

        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n) {
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll ret = minSwaps(arr);
        cout << ret << "\n";
    }

    return 0;
}
