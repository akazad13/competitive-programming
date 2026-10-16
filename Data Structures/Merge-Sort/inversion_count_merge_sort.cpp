/**
 * @file inversion_count_merge_sort.cpp
 * @brief Inversion Count using Merge Sort
 * 
 * Counts the number of inversions (pairs (i, j) such that i < j and a[i] > a[j])
 * in an array using the divide-and-conquer approach of Merge Sort.
 * 
 * Time Complexity:  O(n log n)
 * Space Complexity: O(n) temporary buffer
 */

#include <iostream>
#include <cstdio>

using namespace std;

long long ans = 0;

void mergei(int a[], int i, int j) {
    int ni = ((i + j) / 2) + 1;
    int nj = j + 1;
    int s = i;
    int *arr = new int[j - i + 1];
    int r = ni;
    int k = 0;

    int l = i;
    while (l < ni && r < nj) {
        if (a[l] <= a[r]) {
            arr[k] = a[l];
            l++;
        } else {
            arr[k] = a[r];
            ans += (ni - l); // Number of inversions
            r++;
        }
        k++;
    }
    for (; l < ni; l++, k++)
        arr[k] = a[l];
    for (; r < nj; r++, k++)
        arr[k] = a[r];
    for (k = 0; s < nj; s++, k++)
        a[s] = arr[k];

    delete[] arr;
}

void m_sort(int a[], int i, int j) {
    if (i < j) {
        int mid = (i + j) / 2;
        m_sort(a, i, mid);
        m_sort(a, mid + 1, j);
        mergei(a, i, j);
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        ans = 0;
        scanf("%d", &n);
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        m_sort(a, 0, n - 1);
        cout << ans << "\n";
        delete[] a;
    }
    return 0;
}
