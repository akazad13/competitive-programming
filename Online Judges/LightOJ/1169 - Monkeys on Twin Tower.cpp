#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

int dp[2][1010];
int ti[2][1010];
int jump[2][1010];
int n;

int cal(int tower, int flr)
{

    if(flr>=n)
        return 0;

    if(dp[tower][flr]!=-1) return dp[tower][flr];

    int ret1 = cal(tower,flr+1)+ti[tower][flr];
    int ret2 = cal((tower+1)%2,flr+1)+ti[tower][flr]+jump[tower][flr];

    dp[tower][flr] = min(ret1,ret2);

    return dp[tower][flr];
}

int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        Clear(dp,-1);
        read(n);

        rep(i,0,n)
        {
            read(ti[0][i]);
        }

        rep(i,0,n)
        {
            read(ti[1][i]);
        }

        rep(i,0,n-1)
        {
            read(jump[0][i]);
        }
        rep(i,0,n-1)
        {
            read(jump[1][i]);
        }

        int ret = cal(0,0);
        int ret1 = cal(1,0);
        printf("Case %d: %d\n",Case,min(ret,ret1));
    }

    return 0;
}
