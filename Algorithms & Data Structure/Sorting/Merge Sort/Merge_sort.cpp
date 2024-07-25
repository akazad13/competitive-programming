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

    FOR0(i,leftSubArraySize) {
        leftSubArray[i] = arr[left+i];
    }

    FOR0(i,rightSubArraySize) {
        rightSubArray[i] = arr[mid+1+i];
    }

    int currIndexOfRightSubArray = 0;
    int currIndexOfMergeArray = left;

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
