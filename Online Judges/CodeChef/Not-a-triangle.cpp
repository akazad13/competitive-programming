#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[2020];
    int n,diff,low;

    long long ans;

    while(cin>>n,n)
    {
        ans=0;
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);

        for(int i=n-1;i>=2;i--)
        {
            for(int j=i-1;j>=1;j--)
            {
                diff = arr[i]-arr[j];
                diff;
                low = lower_bound(arr,arr+j,diff)-arr;
                //cout<<low<<endl;
                //cout<<arr[low]<<endl;
               // if(arr[low]==diff && low>0)
                //    low--;
                ans+=low;
            }
        }

        printf("%lld\n",ans);

    }

}
