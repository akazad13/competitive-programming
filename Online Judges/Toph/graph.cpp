#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define  ll long long int
#define  row 1001
#define  column 1001
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define sc(n) scanf("%c",&n);
#define loop(pp,aa,nn) for(pp=aa;pp<nn;pp++)

ll node,edge,st,en;

vector<ll> g[200];
bool vis[200];

ll dp[102];


ll dfs(ll u)
{
    if(u==en) return 1;

    if(dp[u]!=-1) return dp[u];
    vis[u]=1;

    ll ans=0;

    int s = g[u].size();
    for(int i=0;i<s;i++)
    {
        int v  = g[u][i];
        if(vis[v])
            continue;
        ans+=dfs(v);
    }
    vis[u]=0;
    return dp[u]=ans;
}


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ll test, caseno,i,j,k, cnt;

	ll a,b;

	sl(test);

	loop(caseno,1,test+1)
	{
        sl(node);
        sl(edge);
        sl(st);
        sl(en);

        loop(i,0,node+1)
        {
            g[i].clear();
            vis[i] = 0;
            dp[i]=-1;
        }

        loop(i,0,edge)
        {
            sl(a);
            sl(b);

            g[a].push_back(b);
            g[b].push_back(a);


        }

        ll ret = dfs(st);

        printf("Case %lld: %lld\n",caseno,ret);

	}


	return 0;
}


