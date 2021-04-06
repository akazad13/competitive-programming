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


inline int Set(int N, int pos)
{
    return N= N|(1<<pos);
}

inline int Reset(int N, int pos)
{
    return N= N & ~(1<<pos);
}

inline bool check(int N, int pos)
{
    return (bool) (N&(1<<pos));
}

char str[20];
int n,k;
int len;

lld dp[1<<16][20];


lld solve(int mask, int rem)
{
    if(mask==((1<<len)-1))
    {
        if(rem==0)
            return 1;
        else
            return 0;
    }

    if(dp[mask][rem]!=-1) return dp[mask][rem];

    lld ret=0;
    for(int i=0;i<len;i++)
    {
        if(check(mask,i)==0)
        {
            int p;
            if(str[i]>='0' && str[i]<='9')
                p = str[i]-'0';
            else
                p = str[i]-'A'+10;
            ret+=solve(Set(mask,i),(n*rem+p)%k);
        }
    }

    dp[mask][rem] = ret;

    return dp[mask][rem];
}


int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        Clear(dp,-1);
        read(n); read(k);
        gets(str);
        len = strlen(str);

        printf("Case %d: %lld\n",Case,solve(0,0));
    }

    return 0;
}

