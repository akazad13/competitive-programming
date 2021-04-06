#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[2010];

int main()
{
    int n;
    long long int res;
    int test;
    cin>>test;

    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%d",&n);
        res=0;

        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);

        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                res+= upper_bound(arr,arr+n,(arr[i]+arr[j]-1))-upper_bound(arr,arr+n,arr[j]);
            }
        }
        printf("Case %d: %d\n",Case,res);
    }


    return 0;

}


