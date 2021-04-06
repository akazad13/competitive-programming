#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define Clear(a,b) memset(a,b,sizeof(a))

#define inf 1000000000

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
int dp[100005];
int n, make ;

int val[101], num[101];
int need[100005];

int solve()
{
    Clear(dp,0);

    dp[0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=make;j++)
        {
            if(dp[j]==0)
                need[j] = inf;
            else
                need[j]=0;
        }

        for(int j=0 ;j<=make;j++)
        {
            int next = j+val[i];

            if( next<=make && dp[next]==0 && need[j]+1<need[next] && need[j]+1<=num[i])
            {
                dp[next]=1;
                need[next] = need[j]+1;
            }
        }
    }

    int cnt=0;

    for(int i=1;i<=make;i++)
    {
        if(dp[i])
            cnt++;
    }

    return cnt;
}

int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(make);

        for(int i=0;i<n;i++)
        {
            read(val[i]);
        }

        for(int i=0;i<n;i++)
        {
            read(num[i]);
        }

        int ret = solve();

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}

