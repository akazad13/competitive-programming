#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define Clear(a,b) memset(a,b,sizeof(a))

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

lld dp[31][31][901];

lld solve(lld n, lld m, lld k)
{
    if(k>n || k>m)
        return 0;

    if(k==0)
        return 1;

    if(m==1)
        return n;

    if(dp[n][m][k]!=-1) return dp[n][m][k];

    return n*solve(n-1,m-1,k-1)+ solve(n,m-1,k);
}

int main()
{
    int test,i,j,Case;
    lld n,k;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(k);

        Clear(dp,-1);

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int l=0;l<=k;l++)
                {
                    dp[i][j][l]=-1;
                }
            }
        }

        printf("Case %d: ",Case);

        printf("%lld\n",solve(n,n,k));
    }

    return 0;
}


