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
/***************************************/
char str[70];
lld dp[70][70];

lld solve(int i, int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    lld &ret = dp[i][j];

    if(ret!=-1) return ret;

    if(str[i]==str[j])
    {
        ret=1+solve(i,j-1)+solve(i+1,j);
    }
    else
    {
        ret=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
    }
    return ret;
}

int main()
{
    int test,i,j,Case,n,m;
    read(test);
    rep(Case,1,test+1)
    {
        gets(str);

        Clear(dp,-1);

        int len = strlen(str);
        lld ret = solve(0,len-1);

        printf("Case %d: %lld\n",Case,ret);
    }

    return 0;
}

