/**
 * @file ismake.cpp
 * @brief Subset Sum / Coin Change Reachability (Can we make target sum?)
 * 
 * Determines whether a target amount `make` can be formed using a subset of
 * given coins.
 * 
 * Time Complexity:  O(noOfCoin * make)
 * Space Complexity: O(noOfCoin * make) (can be reduced to O(make) with 1D DP)
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    int noOfCoin, make;
    if (!(cin >> noOfCoin >> make)) return 0;

    vector<int> coin(noOfCoin + 1);
    for (int i = 1; i <= noOfCoin; i++) {
        cin >> coin[i];
    }

    vector<vector<bool>> dp(noOfCoin + 1, vector<bool>(make + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= noOfCoin; i++) {
        for (int j = 0; j <= make; j++) {
            if (j < coin[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - coin[i]]);
        }
    }

    cout << (dp[noOfCoin][make] ? "Possible\n" : "Not Possible\n");

    return 0;
}
