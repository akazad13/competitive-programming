#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define mx  30010
vector<int> g[mx],cost[mx];
int perNodeCost[mx];
int Node_cost[mx];
int node;


void bfs(int src)
{
    int mxx=-11;
    queue<int>Q;
    Q.push(src);
    bool visited[mx]={false};
    CLEAR(Node_cost,0);
    visited[src]=true;
    Node_cost[src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!visited[v])
            {
                Node_cost[v]=Node_cost[u]+cost[u][i];
                if(mxx<Node_cost[v])
                {
                    node=v;
                    mxx=Node_cost[v];
                }
                visited[v]=true;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int main()
{
    int test,u,v,w,n=0;

    scanf("%d",&test);

    for(int Case =1 ; Case<=test; Case++)
    {
        CLEAR(perNodeCost,0);

        for(int i=0;i<n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }

        scanf("%d",&n);

        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);

        }
        node=0;

        bfs(node);

        bfs(node);
        for(int i=0;i<n;i++)
            perNodeCost[i]=Node_cost[i];
        bfs(node);

        for(int i=0;i<n;i++)
            perNodeCost[i]=max(perNodeCost[i],Node_cost[i]);

        printf("Case %d:\n",Case);

        for(int i=0;i<n;i++)
        {
            printf("%d\n",perNodeCost[i]);
        }

    }

    return 0;

}
