/**
 * @file LCS.cpp
 * @brief Longest Common Subsequence (LCS)
 * 
 * Computes the length of the longest subsequence present in both strings,
 * and reconstructs the actual subsequence string.
 * 
 * Time Complexity:  O(n * m) where n = |s1|, m = |s2|
 * Space Complexity: O(n * m) for the DP table
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the length of LCS and reconstructs the LCS string
string getLCS(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct LCS string
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    while (cin >> s1 >> s2) {
        string lcs = getLCS(s1, s2);
        cout << "Length: " << lcs.length() << "\n";
        cout << "LCS:    " << lcs << "\n";
    }

    return 0;
}
