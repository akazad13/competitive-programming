#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int
#define rep(i,a,b) for(i=a;i<b;i++)
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
#define Max 10005


vector<int> G[Max];
int node,edge;
bool visited[Max];
int d[Max];
int low[Max];
vector<pair<int,int> > bridge;
int parent[Max];

void find_bridge(int time, int u)
{
    time +=1;
    low[u]=d[u]=time;
    visited[u]=true;
    int child = 0;
    int i,v;

    rep(i,0,G[u].size())
    {
        v = G[u][i];
        if(v==parent[u]) continue;

        if(visited[v]) //back edge
        {
            low[u] = min(low[u],d[v]);
        }
        else //tree edge
        {
            parent[v]=u;
            find_bridge(time,v);
            low[u] = min(low[u],low[v]);
            if(d[u]<low[v])
            {
                bridge.push_back(make_pair(min(u,v),max(u,v)));
            }
        }
    }
    return ;
}


void dfs()
{
    Clear(visited,0);
    bridge.clear();
    Clear(d,0);
    Clear(low,0);
    Clear(parent,-1);

    int time = 0;
    int i;

    rep(i,0,node)
    {
        if(!visited[i])
        {
            find_bridge(time,i);
        }
    }
    return ;

}


int main()
{
    int test,Case,i,j,u,v,e;
    read(test);
    rep(Case,1,test+1)
    {
        read(node);

        rep(i,0,node+1)
            G[i].clear();

        rep(i,0,node)
        {
            read(u);
            char ch = getchar();
            ch = getchar();
            read(e);
            ch = getchar();
            rep(j,0,e)
            {
                read(v);
                G[u].push_back(v);
                G[v].push_back(u);
            }

        }

        dfs();

        int len = bridge.size();
        sort(bridge.begin(),bridge.end());

        printf("Case %d:\n",Case);

        printf("%d critical links\n",len);

        for(int i=0;i<len;i++)
        {
            printf("%d - %d\n",bridge[i].first,bridge[i].second);
        }

    }

    return 0;
}
