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
/****************************************/
int arr[12];
lld dp[10][10][10];
int n,make;

lld solve(int ind, int len, int last)
{
    if(ind>=n)
    {
        if(len==make)
            return 1;
        else
            return 0;
    }

    if(len==make)
        return 1;
    lld &ret = dp[ind][len][last];

    if(ret!=-1) return ret;
    ret=0;
    int diff;
    for(int i=0;i<n;i++)
    {
        if(last==0)
        {
            diff=0;

        }
        else
        {
            diff = abs(last-arr[i]);
        }

        if(diff<=2)
            ret+=(solve(ind,len+1,arr[i]));
    }
    return ret;
}

int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(make);

        rep(i,0,n)
            read(arr[i]);

        Clear(dp,-1);

        lld ret = solve(0,0,0);

        printf("Case %d: %lld\n",Case,ret);
    }

    return 0;
}


