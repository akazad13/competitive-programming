#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int maxnodes = 100010;

#define inf 1000000000000
#define ll long long int

vector<int> g[maxnodes+10];
vector<ll> cost[maxnodes+10];
vector<int> rg[maxnodes+10];
vector<ll> rcost[maxnodes+10];
ll d[maxnodes+10];
ll p[maxnodes+10];

void init(int n)
{
    for(int i=0;i<=n+2;i++)
    {
        g[i].clear();
        cost[i].clear();
        rg[i].clear();
        rcost[i].clear();
    }
}

void bfs(int src,int n)
{
    for(int i=1;i<=n;i++)  d[i] = inf;
    queue<int> q;
    q.push(src);
    d[src]=0;
    while(!q.empty())
    {
        int u=q.front(); q.pop();

        int len = g[u].size();
        for(int i=0;i<len;i++)
        {
            int v=g[u][i];
            if(d[u]+cost[u][i] < d[v])
            {
                d[v]=d[u]+cost[u][i];
                q.push(v);
            }
        }
    }
}

void rbfs(int src,int n)
{
    for(int i=1;i<=n;i++)  p[i] = inf;
    queue<int> q;
    q.push(src);
    p[src]=0;
    while(!q.empty())
    {
        int u=q.front(); q.pop();

        int len = rg[u].size();
        for(int i=0;i<len;i++)
        {
            int v=rg[u][i];
            if(p[u]+rcost[u][i] < p[v])
            {
                p[v]=p[u]+rcost[u][i];
                q.push(v);
            }
        }
    }
}


int main() {
    //freopen("input.txt","r",stdin);
    int test,Case,u,v;
    int n,m,src,des;
    ll pp,w;

    scanf("%d",&test);
    for(Case=1;Case<=test;Case++)
    {

        scanf("%d %d %d %d %lld",&n,&m,&src,&des,&pp);

         init(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %lld",&u,&v,&w);
            g[u].push_back(v);
            rg[v].push_back(u);
            cost[u].push_back(w);
            rcost[v].push_back(w);
        }

        bfs(src,n);
        rbfs(des,n);

        ll ans=-1;
       // cout<<"-------------"<<endl;
        for(int i=1;i<=n;i++)
        {
            int len = g[i].size();
            for(int j=0;j<len;j++)
            {
                ll cc = cost[i][j];
                int v = g[i][j];

                //cout<<d[i]<<" "<<cc<<" "<<p[v]<<" "<<i<<" "<<v<<endl;

                if(cc+d[i]+p[v]<=pp)
                {
                    ans = max(ans,cc);
                }
            }
        }

        printf("Case %d: %lld\n",Case,ans);

    }

    return 0;
}


