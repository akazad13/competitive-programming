#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)

#define pb push_back
#define VI vector<int>
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 102

int residualCapacity[Max][Max];
int capacity[Max][Max];
VI G[Max];
VI path;
bool vis[Max];

vector< VI > paths;

int par[Max];

bool bfs(int vertex, int source, int sink)
{
    Clear(vis,0);
    queue<int> Q;
    vis[source]=true;
    Q.push(source);

    bool isPath= false;
    int i;

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        rep(i,0,vertex)
        {
            if(vis[i]==0 && residualCapacity[u][i]>0)
            {
                par[i]=u;
                vis[i]=true;
                Q.push(i);

                if(i==sink)
                {
                    isPath=true;
                    break;
                }
            }
        }
    }
    return isPath;
}

int FordFulkarson(int vertex, int source, int sink)
{
    int i,j;
    rep(i,0,vertex)
    {
        rep(j,0,vertex)
        {
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    path.clear();
    paths.clear();

    int max_flow = 0;

    while(bfs(vertex,source,sink))
    {
        int v = sink;
        int flow = INT_MAX;
        while(v!=source)
        {
            path.push_back(v);
            int u = par[v];

            flow = min(flow,residualCapacity[u][v]);
            v=u;
        }
        path.push_back(source);
        max_flow+=flow;
        reverse(path.begin(),path.end());

        paths.push_back(path);
        path.clear();
        v = sink;
        while(v!=source)
        {
            int u = par[v];
            residualCapacity[u][v]-=flow;
            residualCapacity[v][u]+=flow;
            v=u;
        }
    }
    return max_flow;
}

int main()
{
    int vertex,test,Case;
    int source, sink;
    int edge;
    int u,v,i,j,cap;
    int cnt=0;

    read(test);

    rep(Case,1,test+1)
    {
        Clear(capacity,0);

        read(vertex); read(edge);

        rep(i,0,2*vertex+1)
        {
            rep(j,0,2*vertex+1)
            {
                capacity[i][j]=0;
                capacity[j][i]=0;
            }
        }

        capacity[1][vertex+1]=100000000;
        capacity[vertex][2*vertex]=100000000;

        rep(i,2,vertex)
        {
            read(u);
            capacity[i][vertex+i]+= u;
            capacity[vertex+i][i]+= u;
        }

        rep(i,0,edge)
        {
            read(u); read(v);
            read(cap);

            capacity[vertex+u][v]+=cap;
            capacity[v+vertex][u]+=cap;
        }

        source  = 1;
        sink = vertex+vertex;

        int ret  = FordFulkarson(2*vertex+1, source, sink);

        printf("Case %d: %d\n",Case,ret);
    }
    return 0;
}


