#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define pb push_back
#define VI vector<int>

#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 210

int residualCapacity[Max][Max];
int capacity[Max][Max];
VI G[Max];
VI path;
bool vis[Max];

vector< VI > paths;

int par[Max];

void PrintPath()
{
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<"->";
    cout<<endl;
}

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

        read(vertex);

        rep(i,1,vertex+1)
        {
            read(u);
            capacity[i][vertex+i]+= u;
        }

       read(edge);

        rep(i,0,edge)
        {
            read(u); read(v);
            read(cap);

            capacity[vertex+u][v]+=cap;
        }

        read(source); read(sink);

        rep(i,0,source)
        {
            read(u);
            capacity[0][u]=100000000;
        }
        rep(i,0,sink)
        {
            read(u);
            capacity[vertex+u][2*vertex+1]=100000000;
        }
        int ret  = FordFulkarson(2*vertex+2, 0, 2*vertex+1);

        printf("Case %d: %d\n",Case,ret);
    }



    return 0;
}



