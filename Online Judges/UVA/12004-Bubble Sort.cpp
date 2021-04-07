#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        long long int n;
        cin>>n;

        long long int count= (n*(n-1))/2;


        if(count%2==0)
            printf("Case %d: %lld\n",i,(count/2));
        else
        {
            printf("Case %d: %lld/%d\n",i,count,2);
        }
    }

    return 0;
}
