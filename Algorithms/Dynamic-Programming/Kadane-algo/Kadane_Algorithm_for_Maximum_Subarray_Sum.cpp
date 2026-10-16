/**
 * @file Kadane_Algorithm_for_Maximum_Subarray_Sum.cpp
 * @brief Kadane's Algorithm for Maximum Contiguous Subarray Sum
 * 
 * Computes the maximum sum of any contiguous subarray in 1D array.
 * 
 * Time Complexity:  O(n)
 * Space Complexity: O(1) auxiliary
 */

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
#define ll long long
#define scl(n) scanf("%lld", &n)
#define FOR0(i, n) for (ll i = 0; i < n; i++)
#define FOR1(i, n) for (ll i = 1; i <= n; i++)

ll arr[1000010];

ll Kadane(ll n)
{
    ll maxSum = -1 * INT_MAX, cur = 0;
    FOR0(i, n)
    {
        cur = max(arr[i], cur + arr[i]);
        maxSum = max(maxSum, cur);
    }
    return maxSum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ll n, test;
    scl(test);
    FOR1(cs, test)
    {
        scl(n);
        FOR0(i, n)
        {
            scl(arr[i]);
        }
        ll maxSum = Kadane(n);
        printf("%lld\n", maxSum);
    }
    return 0;
}
