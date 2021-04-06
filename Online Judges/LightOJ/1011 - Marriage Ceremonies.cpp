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

int pri_ind[17][17];
int n;

int dp[1<<16];

int no_set(int mask)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(check(mask,i))
            cnt++;
    }

    return cnt;
}

int solve(int mask)
{
    if(mask==(1<<16)-1)
        return 0;
    if(dp[mask]!=-1) return dp[mask];

    int ret=0;

    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            ret = max(ret,solve(Set(mask,i))+ pri_ind[i][no_set(mask)]);
        }
    }

    return dp[mask]=ret;
}


int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        Clear(dp,-1);

        rep(i,0,n)
        {
            rep(j,0,n)
            {
                read(pri_ind[i][j]);
            }
        }

        int ret = solve(0);

        printf("Case %d: %d\n",Case,ret);
    }
    return 0;
}

