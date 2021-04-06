#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int find_GCD(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    find_GCD(b,a%b);
}

int main()
{
    int test,n;

    int arr[120];

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>n;

        int count=0;

        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            if(arr[j]<0)
                count++;
        }

        int diff=n-count;

        if(diff<=0)
        {
            printf("Case %d: inf\n",i);
            continue;
        }

       int sum = 0;

       for(int j=0;j<n;j++)
        {
            sum+=abs(arr[j]);
        }

        int GCD;
        GCD = find_GCD(sum,diff);
        printf("Case %d: %d/%d\n",i,(sum/GCD),(diff/GCD));
    }
    return 0;
}
