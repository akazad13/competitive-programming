#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define scan(n) scanf("%d", &n)
#define print(n) printf("%d", n);
#define space() printf(" ");
#define newLine() printf("\n");
#define FOR(i, a, b) for (int i = a; i <= b; i++)

void merge(vector<int> &nums, int left, int mid, int right)
{
    // decare left and right subarray indices
    int const leftSubArraySize = mid - left + 1;
    int const rightSubArraySize = right - mid;

    // declare and initialize left and right subarrays
    auto *leftSubArray = new int[leftSubArraySize],
         *rightSubArray = new int[rightSubArraySize];

    // copy data to left subarray
    FOR(i, 0, leftSubArraySize - 1)
    {
        leftSubArray[i] = nums[left + i];
    }

    // copy data to right subarray
    FOR(i, 0, rightSubArraySize - 1)
    {
        rightSubArray[i] = nums[mid + 1 + i];
    }

    int currIndexOfRightSubArray = 0;
    int currIndexOfMergeArray = left;

    // Merge the two subarrays into the original array
    FOR(i, 0, leftSubArraySize - 1)
    {
        if (currIndexOfRightSubArray >= rightSubArraySize)
        {
            nums[currIndexOfMergeArray++] = leftSubArray[i];
        }
        else
        {
            while (
                currIndexOfRightSubArray < rightSubArraySize && rightSubArray[currIndexOfRightSubArray] <= leftSubArray[i])
            {
                nums[currIndexOfMergeArray++] = rightSubArray[currIndexOfRightSubArray++];
            }
            nums[currIndexOfMergeArray++] = leftSubArray[i];
        }
    }

    // Deallocate memory
    delete[] leftSubArray;
    delete[] rightSubArray;
    return;
}

void mergeSort(vector<int> &nums, int begin, int end)
{
    if (begin < end)
    {
        // get the middle of the partition
        int mid = begin + (end - begin) / 2;

        // Sort both halves recursively
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid + 1, end);

        // Merge the sorted halves into the original array
        merge(nums, begin, mid, end);
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

        mergeSort(nums, 0, n - 1);

        FOR(i, 0, n - 1)
        {
            print(nums[i]);
            space();
        }
        newLine();
    }
    return 0;
}
