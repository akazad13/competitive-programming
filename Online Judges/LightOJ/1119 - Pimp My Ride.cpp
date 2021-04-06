#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define read(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)
#define Clear(a,b) memset(a,b,sizeof(a))


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

int w[20][20];
int n;
int dp[(1<<15)+2];

int cal(int mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int Min = 1<<28;
    int i,j;

    rep(i,0,n)
    {
        if(check(mask,i)==0)
        {
            int price = w[i][i];
            rep(j,0,n)
            {
                if(i!=j and check(mask,j)!=0)
                {
                    price+=w[i][j];
                }
            }

            int ret = price+cal(Set(mask,i));
            Min = min(Min,ret);
        }

    }
    return dp[mask]=Min;
}


int main()
{
    int test,i,j;
    read(test);
    for(int Case=1;Case<=test;Case++)
    {
        Clear(dp,-1);
        read(n);

        rep(i,0,n)
        {
            rep(j,0,n)
            {
                read(w[i][j]);
            }
        }
        int ret = cal(0);
        Case(Case);
        write(ret);
    }

    return 0;
}

