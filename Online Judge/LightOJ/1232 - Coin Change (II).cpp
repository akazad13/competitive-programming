#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MOD 100000007
#define lld long long int

int coins[200];
int dp[102][10100];
int n,k;
lld solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j<coins[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = (dp[i-1][j]%MOD+dp[i][j-coins[i]]%MOD)%MOD;
            }
        }
    }
    return dp[n][k];
}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        cin>>n>>k;
        for(int j=1;j<=n;j++)
        {
            cin>>coins[j];
        }
        printf("Case %d: %lld\n",i,solve());


    }
    return 0;
}
