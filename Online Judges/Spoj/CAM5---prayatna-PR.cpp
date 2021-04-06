#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

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

#define Max 100010

VI g[Max];
bool vis[Max];


void dfs(int u)
{
    vis[u]=1;

    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];

        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,i,j,Case,n,m,u,v;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m);

        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
        }


        rep(i,0,m)
        {
            read(u); read(v);
            g[u].pb(v);
            g[v].pb(u);
        }

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                cnt++;
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}

