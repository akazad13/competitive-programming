#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define scan(n) scanf("%d", &n)
#define print(n) printf("%d", n);
#define space() printf(" ");
#define newLine() printf("\n");
#define FOR(i, a, b) for (int i = a; i <= b; i++)

int partition(vector<int> &nums, int left, int right)
{
    // Seleting last element as a pivot
    int pivot = nums[right];
    int i = left - 1;

    // move all the elements less than and equal to the pivot to the left side
    // and the elements greater than to the right side
    FOR(j, left, right - 1)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[right]);

    return i + 1;
}

void quickSort(vector<int> &nums, int begin, int end)
{
    if (begin < end)
    {
        // Partition the array and get the pivot index
        int partitionIndex = partition(nums, begin, end);

        // Recursively sort the two partitions
        quickSort(nums, begin, partitionIndex - 1);
        quickSort(nums, partitionIndex + 1, end);
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    int n, totalCase;
    vector<int> nums(100005);

    scan(totalCase);
    FOR(cs, 1, totalCase)
    {
        scan(n);

        FOR(i, 0, n - 1)
        {
            scan(nums[i]);
        }

        quickSort(nums, 0, n - 1);

        FOR(i, 0, n - 1)
        {
            print(nums[i]);
            space();
        }
        newLine();
    }
    return 0;
}
