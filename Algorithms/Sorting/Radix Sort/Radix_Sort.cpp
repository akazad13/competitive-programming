#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
#define scan(n) scanf("%d", &n)
#define print(n) printf("%d", n);
#define space() printf(" ");
#define newLine() printf("\n");
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ReverseFor(i, a, b) for (int i = a; i >= b; i--)

void countingSortByDigit(vector<int> &nums, int exponent)
{
    int n = nums.size();
    int maxNum = 9;

    vector<int> counts(maxNum + 1, 0);

    FOR(i, 0, maxNum)
    {
        counts[i] = 0;
    }

    FOR(i, 0, n - 1)
    {
        int digit = (nums[i] / exponent) % 10;
        counts[digit]++;
    }
    FOR(i, 1, maxNum)
    {
        counts[i] += counts[i - 1];
    }

    vector<int> sortedNums(n);

    ReverseFor(i, n - 1, 0)
    {
        int digit = (nums[i] / exponent) % 10;
        sortedNums[counts[digit] - 1] = nums[i];
        counts[digit]--;
    }

    FOR(i, 0, n - 1)
    {
        nums[i] = sortedNums[i];
    }

    return;
}

void radixsort(vector<int> &nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());

    int exp = 1;
    while (maxNum / exp > 0)
    {
        countingSortByDigit(nums, exp);
        exp *= 10;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    int n, totalCase;

    scan(totalCase);
    FOR(cs, 1, totalCase)
    {
        scan(n);
        vector<int> nums(n);

        FOR(i, 0, n - 1)
        {
            scan(nums[i]);
        }

        radixsort(nums);

        FOR(i, 0, n - 1)
        {
            print(nums[i]);
            space();
        }
        newLine();
    }
    return 0;
}
