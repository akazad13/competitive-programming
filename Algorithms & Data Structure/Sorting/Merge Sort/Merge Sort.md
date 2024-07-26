
# Merge Sort

Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays, then merging them back together to obtain the sorted array.

So, we can say that the process of merge sort is to divide the array into two halves, sort each half, and then merge the sorted halves back together. This process is repeated until the entire array is sorted.

#### Here’s a step-by-step explanation of how merge sort works:

1. Divide: Recursively split the list or array into two halves until they cannot be divided further.

2. Conquer: Sort each subarray individually using the merge sort algorithm.

3. Merge: Combine the sorted subarrays back together in order. Continue this process until all elements from both subarrays are merged.

### Example

    Input:  48 38 27 43 10 30
    Output: 10 27 30 38 43 48



### Code

```cpp
#include<iostream>
#include<cstdio>

using namespace std;
#define sc(n)               scanf("%d",&n)
#define scl(n)              scanf("%lld",&n)
#define print(n)            printf("%d", n);
#define space()             printf(" ");
#define newLine()           printf("\n");
#define FOR0(i,n)           for(int i=0;i<n;i++)
#define FOR1(i,n)           for(int i=1;i<=n;i++)

int arr[100005];

void merge(int left, int mid, int right) {
    int const leftSubArraySize = mid - left + 1;
    int const rightSubArraySize = right - mid;

    // Create temp arrays
    auto *leftSubArray = new int[leftSubArraySize],
         *rightSubArray = new int[rightSubArraySize];

    // Divide values to each subarrays
    FOR0(i,leftSubArraySize) {
        leftSubArray[i] = arr[left+i];
    }

    FOR0(i,rightSubArraySize) {
        rightSubArray[i] = arr[mid+1+i];
    }

    int currIndexOfRightSubArray = 0;
    int currIndexOfMergeArray = left;

    //rearrange the values between left to right to make them sorted
    FOR0(i, leftSubArraySize) {
        if(currIndexOfRightSubArray >= rightSubArraySize) {
            arr[currIndexOfMergeArray++] = leftSubArray[i];
        } else {
            while(
                currIndexOfRightSubArray < rightSubArraySize 
            &&  rightSubArray[currIndexOfRightSubArray] <= leftSubArray[i]
            ) {
                arr[currIndexOfMergeArray++] = rightSubArray[currIndexOfRightSubArray++];
            }
            arr[currIndexOfMergeArray++] = leftSubArray[i];
        }
    }

    //deallocate arrays
    delete[] leftSubArray;
    delete[] rightSubArray;

    return;
}

void mergeSort(int begin, int end) 
{
    if(begin < end) {
        int mid = begin + (end - begin)/2;

        mergeSort(begin, mid);
        mergeSort(mid+1, end);
        merge(begin, mid, end);
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("IO/input.txt", "r", stdin);
        freopen("IO/output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n,totalCase;
    scl(totalCase);
    FOR1(cs,totalCase) {
        sc(n);

        FOR0(i,n) {
            sc(arr[i]);
        }

        mergeSort(0, n-1);
        
        FOR0(i,n) {
            print(arr[i]);
            space();
        }
        newLine();
    }
    return 0;
}

```

### Complexity Analysis:

##### Time Complexity:

- **Best Case**: `O(nlogn)`, When the array is already sorted or nearly sorted.
- **Average Case**: `O(nlogn)`, When the array is randomly ordered.
- **Worst Case**: `O(nlogn)`, When the array is sorted in reverse order.

##### Space Complexity:
- `O(n)`, Additional space is required for the temporary array used during merging.


Tags: sorting, mergesort, divide and conquer