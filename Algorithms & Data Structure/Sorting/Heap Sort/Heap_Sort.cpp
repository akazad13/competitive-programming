#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define scan(n) scanf("%d", &n)
#define print(n) printf("%d", n);
#define space() printf(" ");
#define newLine() printf("\n");
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define reverseFor(i, a, b) for (int i = a; i >= b; i--)

void heapify(vector<int> &nums, int n, int curIndex)
{
    int leftChildIndex = 2 * curIndex + 1;
    int rightChildIndex = 2 * curIndex + 2;
    int largest = curIndex;

    if (leftChildIndex < n && nums[leftChildIndex] > nums[largest])
        largest = leftChildIndex;

    if (rightChildIndex < n && nums[rightChildIndex] > nums[largest])
        largest = rightChildIndex;

    if (largest != curIndex)
    {
        swap(nums[curIndex], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int> &nums, int n)
{
    reverseFor(i, n / 2 - 1, 0)
    {
        heapify(nums, n, i);
    }

    reverseFor(i, n - 1, 1)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
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

        heapSort(nums, n);

        FOR(i, 0, n - 1)
        {
            print(nums[i]);
            space();
        }
        newLine();
    }
    return 0;
}
