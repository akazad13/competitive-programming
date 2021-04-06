#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
#define eps 1e-9
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)

#define MOD 1000000007
#define INF (1ll<<45)

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
/*********************************************/

int deg[20];
ll g[20][20];
ll n,m,u,v,w;
ll dp[1<<16];

ll solve(int mask)
{
    if(mask==0)
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];

    ll ret = 1212343564324;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( check(mask,i)&& check(mask,j))
            {
                ll p = mask;
                p = Reset(p,i);
                p = Reset(p,j);

                ret = min(ret,solve(p)+g[i][j]);
            }
        }
    }

    return dp[mask]=ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);
    int test,Case;


    read(test);

    for(Case=1;Case<=test;Case++)
    {
        Clear(deg,0);
        Clear(dp,-1);

        ll res=0;

        read(n); read(m);

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                g[i][j]=INF;
        }

        for(int i=0;i<m;i++)
        {
            read(u); read(v); read(w);
            u--; v--;
            deg[u]++;
            deg[v]++;

            res+=w;

            if(g[u][v]>w)
            {
                g[u][v]=w;
                g[v][u]=w;
            }
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(g[i][j]>g[i][k]+g[k][j])
                    {
                        g[i][j]=g[i][k]+g[k][j];
                    }
                }
            }
        }

        int mask = 0;

        for(int i=0;i<n;i++)
        {
            if(deg[i]%2)
            {
                mask = mask|(1<<i);
            }
        }

        ll ret = solve(mask);

        printf("Case %d: %lld\n",Case,ret+res);

    }



    return 0;
}




