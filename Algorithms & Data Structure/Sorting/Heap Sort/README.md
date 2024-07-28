
# Heap Sort

Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.


### Algorithm

First, convert the array into a heap data structure using the heapify process. Then, repeatedly delete the root node of the max-heap, replace it with the last node in the heap, and heapify the root. Repeat this process until the size of the heap is greater than 1.

Steps to perform Heap Sort:

1. Build a heap from the given input array.
2. Repeat the following steps until the heap contains only one element:
    - Swap the root element of the heap (the largest element) with the last element of the heap.
    - Remove the last element of the heap (now in its correct position).
    - Heapify the remaining elements of the heap.
3. The sorted array is obtained by reversing the order of the elements in the input array.

### Example


### Code

```cpp
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

```

### Complexity Analysis:

##### Time Complexity:

- `O(nlogn)` 

##### Space Complexity:
- `O(logn)`, due to the recursive call stack. However, auxiliary space can be `O(1)` for iterative implementation.


---
Tags: sorting, heapsort
