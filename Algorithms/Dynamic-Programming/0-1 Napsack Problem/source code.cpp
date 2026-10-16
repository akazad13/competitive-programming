/**
 * @file source code.cpp
 * @brief 0-1 Knapsack Problem (Recursive Top-Down with Memoization)
 * 
 * Given n items with weights and profits/costs, find the maximum profit
 * achievable with a knapsack of capacity CAP such that each item can be
 * picked at most once.
 * 
 * Time Complexity:  O(n * CAP)
 * Space Complexity: O(n * CAP) for the DP table + O(n) recursion stack
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_W 1000

int n;
int dp[MAX_N + 1][MAX_W + 1];
int weight[MAX_N + 1];
int cost[MAX_N + 1];
int CAP;

int func(int i, int w) {
    if (i == n + 1) return 0;
    if (dp[i][w] != -1) return dp[i][w];

    int profit1 = 0;
    if (w + weight[i] <= CAP)
        profit1 = cost[i] + func(i + 1, w + weight[i]);

    int profit2 = func(i + 1, w);

    return dp[i][w] = max(profit1, profit2);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));

    if (scanf("%d %d", &n, &CAP) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &weight[i], &cost[i]);
    }

    printf("Max Profit: %d\n", func(1, 0));

    return 0;
}
