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
vector<pair<int,int> > edges;
map< pair<int,int> , bool> Bridge;
map<int,int> res;
map<int,int> :: iterator it;
int parent[Max];

void find_bridge(int time, int u)
{
    time +=1;
    low[u]=d[u]=time;
    visited[u]=true;
   // cout<<u<<endl;
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
                Bridge[make_pair(u,v)]=1;
                Bridge[make_pair(v,u)]=1;
            }
        }
    }
    return ;
}

void dfs()
{
    Clear(visited,0);
    Bridge.clear();
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

int color[Max];
int cnt;

bool bicolor(int u, int col)
{
    visited[u]=1;
    cnt++;
    color[u]=col;

    bool ret=1;

    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(!visited[v])
        {
            ret = (ret& bicolor(v,(col+1)%2));
        }
        else
        {
            if((col+1)%2 !=color[v])
            {
                ret = 0;
            }
        }
    }

    return ret;
}


int main()
{
    int test,Case,i,j,u,v;
    read(test);
    rep(Case,1,test+1)
    {
        edges.clear();
        read(node);
        read(edge);

        rep(i,0,node+1)
            G[i].clear();

        rep(i,0,edge)
        {
            read(u); read(v);
            edges.push_back(make_pair(u,v));
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs();

        rep(i,0,node+1)
            G[i].clear();

        int len = edges.size();

        rep(i,0,len)
        {
            u = edges[i].first;
            v = edges[i].second;

            if(Bridge[make_pair(u,v)]!=1)
            {
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }

        Clear(visited,0);
        Clear(color,0);

        lld ans=0;

        rep(i,0,node)
        {
            if(!visited[i])
            {
                cnt=0;
                bool ret= bicolor(i,0);
                if(ret==0 && cnt>1)
                {
                    ans+=cnt;
                }
            }
        }
        printf("Case %d: %lld\n",Case,ans);
    }
    return 0;
}
