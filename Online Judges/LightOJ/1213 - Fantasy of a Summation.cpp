#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int

lld solve(lld n, lld k, lld MOD)
{
    if(k==0)
        return 1;
    if(k%2==1)
        return ((n%MOD)*solve(n,k-1,MOD)%MOD)%MOD;
    lld res = solve(n,k/2,MOD)%MOD;
    return (res*res)%MOD;
}

int main()
{
    int test;
    lld n,k,MOD,res,num;

    cin>>test;

    for(int Case = 1; Case<=test; Case++)
    {
        res = 0;

        scanf("%lld %lld %lld",&n,&k,&MOD);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&num);
            res+=num%MOD;
        }
        res = res%MOD;

        res = (res*k)%MOD;

        res = (res*solve(n,k-1,MOD))%MOD;

        printf("Case %d: %lld\n",Case,res);
    }

    return 0;
}
