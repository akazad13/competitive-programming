#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define pb push_back

#define Clear(a,b) memset(a,b,sizeof(a))
//istringstream is()

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

int n,m;
vector<int> adj[20];
bool path[(1<<16)+1];
int dp[(1<<16)+1];

bool vis[16][(1<<16)+1];


void dfs(int u, int mask)
{
    path[mask]=1;
    vis[u][mask]=1;

    int s = adj[u].size();

    for(int i=0;i<s;i++)
    {
        int v = adj[u][i];

        if(vis[v][mask|(1<<v)]==0)
        {
            dfs(v, (mask|(1<<v)));
        }
    }

    return ;
}

int solve(int mask)
{
    if(mask==0)
        return 0;

    if(dp[mask]!=-1) return dp[mask];

    int ret = 20;

    for(int i=mask; i>0 ;  i=(mask&(i-1)))  // mask er nicher ta
    {
        if(path[i])
            ret = min(ret,1+solve(mask^i));
    }
    return dp[mask]=ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case,u,v;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m);

        for(int i=0;i<n;i++)
            adj[i].clear();

        for(int i=0;i<m;i++)
        {
            read(u); read(v);

            u--; v--;

            adj[u].pb(v);
        }

        Clear(vis,0);
        Clear(path,0);
        Clear(dp,-1);

        for(int i=0;i<n;i++)
        {
            dfs(i,(1<<i));
        }

       int ret = solve((1<<n)-1);

       printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}
