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

/*******************************************/
int arr[101];
int dp[102][102];
bool seen[102][102];
int n;

int solve(int i, int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return arr[i];

    if(seen[i][j]) return dp[i][j];

    seen[i][j]=true;

    int sum=0;
    int Max=-1000000000;
    for(int k=i;k<=j;k++)
    {
        sum+=arr[k];

        Max = max(Max,sum-solve(k+1,j));
    }

    sum=0;

    for(int k=j;k>=i;k--)
    {
        sum+=arr[k];

        Max = max(Max,sum-solve(i,k-1));
    }
    dp[i][j]=Max;
    return dp[i][j];
}

int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);
        rep(i,0,n)
            read(arr[i]);

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                seen[i][j]=0;
        int res = solve(0,n-1);

        printf("Case %d: %d\n",Case,res);
    }

    return 0;
}




