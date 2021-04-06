#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
ull p,arr[20];
int n;
bool isOdd;

ull dp[1<<15];


ull solve(int mask)
{
    ull lcm = 1;

    ull m = mask;

    for(int i=0;i<n;i++)
    {
        if(dp[mask]!=-1)
        {
            lcm = ((lcm*dp[mask])/__gcd(lcm,dp[mask]));
            break ;
        }
        if(mask&(1<<i))
        {
            lcm = ((lcm*arr[i])/__gcd(lcm,arr[i]));
            mask^=(1<<i);
        }
    }

    for(int i=0;i<n;i++)
    {

        if(m&(1<<i))
        {
            isOdd^=1;
        }
    }

    dp[m] = lcm;
    return lcm;
}



int main()
{
    int test;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%llu %d",&p,&n);

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        int limit = 1<<n;
        ull ret;
        ull ans=p;

        dp[0]=1;
        for(int i=1;i<limit;i++)
        {
            isOdd = false;
            ret = solve(i);


            if(isOdd)
                ans-=(p/ret);
            else
                ans+=(p/ret);
        }

        printf("Case %d: %llu\n",Case,ans);
    }

    return 0;
}
