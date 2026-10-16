/**
 * @file NoOfPos_BST.cpp
 * @brief Number of Possible Binary Search Trees (Catalan Numbers)
 * 
 * Given n distinct keys (1 to n), calculates the number of structurally unique
 * Binary Search Trees (BST) that can be formed.
 * This is given by the n-th Catalan number:
 *   C_n = sum(C_i * C_{n-1-i}) for i = 0 to n-1, with C_0 = 1, C_1 = 1.
 * 
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <cstring>

using namespace std;

#define lld long long int

lld TC[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(TC, 0, sizeof(TC));
    int n;
    if (!(cin >> n)) return 0;

    TC[0] = 1;
    TC[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            TC[i] += TC[j] * TC[i - j - 1];
        }
    }

    cout << TC[n] << "\n";

    return 0;
}
