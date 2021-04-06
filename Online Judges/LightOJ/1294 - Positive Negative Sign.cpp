#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    long long int n,m;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        scanf("%lld %lld",&n,&m);
        long long int res;

        if((n/m)%2==0)
        {
            res=(m*n)/2;
        }
        else
        {
            res= -((m*(n-m))/2)-((m*(m+1))/2);
        }

        printf("Case %d: %lld\n",i,res);
    }
    return 0;
}
