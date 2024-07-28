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

void countingSort(vector<int> &nums)
{
    int n = nums.size();
    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> count(maxNum + 1, 0);

    FOR(i, 0, n - 1)
    {
        count[nums[i]]++;
    }
    FOR(i, 1, maxNum)
    {
        count[i] += count[i - 1];
    }

    vector<int> sortedNums(n);

    ReverseFor(i, n - 1, 0)
    {
        sortedNums[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }

    nums = sortedNums;
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

        countingSort(nums);

        FOR(i, 0, n - 1)
        {
            print(nums[i]);
            space();
        }
        newLine();
    }
    return 0;
}
