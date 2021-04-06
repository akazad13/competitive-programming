#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define Clear(a,b) memset(a,b,sizeof(a))
#define lim 10010
#define pb push_back
#define ull unsigned long long int

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

vector<int> g[lim];
int par[lim], des[lim], low[lim], AP[lim], node, edge, timer;
bool vis[lim];

ull res,ways;
int compo, APoints;

void find_AP(int u)
{
    low[u]=des[u]=timer++;
    vis[u]=1;
    int child=0;

    int Size = g[u].size();

    for(int i=0;i<Size;i++)
    {
        int v = g[u][i];

        if(par[u]==v) continue;

        if(vis[v])
        {
            low[u]= min(low[u],des[v]);
        }
        else
        {
            par[v]=u;
            find_AP(v);
            low[u]=min(low[u],low[v]);

            if(des[u]<=low[v] && par[u]!=-1)
            {
                AP[u]=1;
            }
            child++;
        }

        if(child>1 && par[u]==-1) //root
        {
            AP[u]=1;
        }
    }
}

void articulation_point()
{
    for(int i=0;i<node;i++)
    {
        vis[i]=AP[i]=0;
        par[i]=-1;
    }

    timer=0;

    for(int i=0;i<node;i++)
    {
        if(!vis[i])
        {
            find_AP(i);
        }
    }

    return ;
}

void dfs(int u)
{
    vis[u]=1;
    ways++;

    int Size = g[u].size();

    for(int i=0;i<Size;i++)
    {
        int v = g[u][i];

        if(!vis[v] && !AP[v])
        {
            dfs(v);
        }

       // cout<<u<<" "<<v<<" "<<compo<<" "<<AP[v]<<endl;

        if(!vis[v] && AP[v]!= compo)
        {
            APoints++;
            AP[v]=compo;
        }
    }
}

int main()
{
    int Case, test, u, v;

    read(test);

    for(Case = 1; Case<=test; Case++)
    {
        read(node); read(edge);

        for(int i=0;i<node;i++)
        {
            g[i].clear();

        }

        for(int i=0;i<edge;i++)
        {
            read(u); read(v);

            g[u].pb(v);
            g[v].pb(u);
        }

        articulation_point();


        for(int i=0;i<node;i++)
            vis[i]=0;

        ll shaft=0;
        res=1; compo=1;

        for(int i=0;i<node;i++)
        {
            if(!vis[i] && !AP[i])
            {
                compo++;
                ways=0;
                APoints=0;
                dfs(i);

                if(APoints<2)
                {
                    res*=ways;
                    shaft++;
                }

            }
        }

        if(shaft<2)
        {
            shaft = 2;
            res = node*(node-1);
            res/=2;

        }

        printf("Case %d: %lld %llu\n",Case,shaft, res);
    }

    return 0;
}
