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

int arr[102];
int n,k,w;

int dp[102][102];

int solve(int ind, int used)
{
    if(ind>=n || used>=k)
        return 0;

    if(dp[ind][used]!=-1) return dp[ind][used];
    int low = arr[ind];
    int high = low+w;
    int i;

    for(i=ind;i<n;i++)
    {
        if(arr[i]>high)
            break ;
    }
    dp[ind][used] = max((solve(i,used+1)+(i-ind)),solve(ind+1,used));

    return dp[ind][used];
}


int main()
{
    int test,i,j,Case,p;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);read(w); read(k);

        Clear(dp,-1);

        rep(i,0,n)
        {
            read(p); read(arr[i]);
        }
        sort(arr,arr+n);
        int ret = solve(0,0);
        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}

