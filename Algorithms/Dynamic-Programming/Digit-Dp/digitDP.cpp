/**
 * @file digitDP.cpp
 * @brief Digit DP - Count numbers in [A, B] divisible by K whose digit sum is also divisible by K
 * 
 * Classic Digit DP problem (LightOJ 1068 - Investigation).
 * State: dp[pos][sum % k][rem % k][is_tight]
 * 
 * Time Complexity:  O(len * K * K * 10)
 * Space Complexity: O(len * K * K * 2)
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define rep(i, p, n) for (i = p; i < n; i++)
#define lld long long int
#define Clear(a, b) memset(a, b, sizeof(a))

int k;
lld dp[12][100][100][2];

lld solve(const char str[], int n, int sum, int rem, int var) {
    if (n >= (int)strlen(str)) {
        if (rem == 0 && sum == 0)
            return 1;
        else
            return 0;
    }
    lld &ret = dp[n][sum][rem][var];
    if (ret != -1) return ret;

    ret = 0;
    int en = (var == 0) ? 9 : (str[n] - '0');

    int j = 0;
    for (j = 0; j < en; j++) {
        ret += solve(str, n + 1, (sum + j) % k, (10 * rem + j) % k, 0);
    }
    ret += solve(str, n + 1, (sum + j) % k, (10 * rem + j) % k, var);
    return ret;
}

int main() {
    int test, Case;
    char low[15];
    char high[15];

    if (scanf("%d", &test) != 1) return 0;

    for (Case = 1; Case <= test; Case++) {
        scanf("%s %s %d", low, high, &k);
        if (k > 100) {
            printf("Case %d: 0\n", Case);
            continue;
        }
        Clear(dp, -1);
        int ret1 = solve(low, 0, 0, 0, 1);

        Clear(dp, -1);
        int ret2 = solve(high, 0, 0, 0, 1);

        int res = ret2 - ret1;

        int rem = 0, sum = 0;
        int len_low = strlen(low);
        for (int i = 0; i < len_low; i++) {
            rem = (10 * rem + low[i] - '0') % k;
            sum = (sum + low[i] - '0') % k;
        }
        if (rem == 0 && sum == 0)
            res++;

        printf("Case %d: %d\n", Case, res);
    }

    return 0;
}
