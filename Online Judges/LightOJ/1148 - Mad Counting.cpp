#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[1000010];

int main()
{
    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        for(int j=0;j<1000005;j++)
            arr[j]=0;
        int n,ind;
        cin>>n;

        for(int j=0;j<n;j++)
        {
            cin>>ind;
            arr[ind]++;
        }

        int count=0;

        for(int j=0;j<=1000000;j++)
        {
            if(arr[j]>0)
            {
                if(j+1<arr[j])
                {
                    int div = ceil((double)arr[j]/(double)(j+1));
                    count += div*(j+1);
                }
                else
                    count+=j+1;
            }
        }

        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
