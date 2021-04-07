#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={1,5,10,25,50};

    int res[7500];

    for(int i=0;i<=7490;i++)
    {
        res[i]=1;
    }

    for(int i=1;i<5;i++)
    {
        for(int j=a[i];j<=7490;j++)
        {
            res[j]+=res[j-a[i]];
        }
    }

    int n;

    while(cin>>n)
    {
        cout<<res[n]<<"\n";
    }

    return 0;
}
