#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 505

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

double dp[102];
double arr[102];
int n;

double solve(int ind)
{
    int i,j;

    if(ind>=n)
    {
        return 0;
    }

    if(dp[ind]!=-1) return dp[ind];
    double ret=0;
    rep(i,1,7)
    {
            ret+=solve(ind+i);
    }
    if(ind==n-1)
        return dp[ind]=arr[ind];

    ret = ret/(min(6,n-ind-1)*1.0)+arr[ind];

    return dp[ind]=ret;
}

int main()
{

    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        rep(i,0,102)
            dp[i]=-1;
        read(n);

        rep(i,0,n)
            read(arr[i]);
        double ret = solve(0);

        printf("Case %d: %.10f\n",Case,ret);
    }

    return 0;
}
