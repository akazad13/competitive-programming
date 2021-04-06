#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100002

int d[11][mx];

struct graph
{
    int w;
    int v;
    bool flag;
};

struct node
{
    int u;
    int cost;
    int used;
    bool operator > ( const node& p ) const { return cost > p.cost; }
};
vector<graph> g[mx];

int dijkstra(int n,int No)
{
    memset(d,63,sizeof(d));
    priority_queue <node,vector<node>, greater<node> > q;
    node A,B;
    A.u=A.cost=A.used=0;
    q.push(A);
    d[0][0]=0;
    while(!q.empty())
    {
        A=q.top(); q.pop();

        if(A.cost != d[A.used][A.u]) continue;

        if(A.u==(n-1)) return A.cost;
        for(int i=0;i<(int)g[A.u].size();i++)
        {
            B.u=g[A.u][i].v;
            B.used = (g[A.u][i].flag? 1:0)+A.used;
            B.cost = A.cost+g[A.u][i].w;

            if(B.cost < d[B.used][B.u] && B.used<=No)
            {
                d[B.used][B.u]=B.cost;
                q.push(B);
            }
        }
    }
    return -1;
}
int main()
{
    int test,n,m,k,No,u,v,w;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        bool flag;
        graph aNode;
        for(int j=0;j<mx;j++)
        {
            g[j].clear();
        }
        scanf("%d %d %d %d",&n,&m,&k,&No);
        flag=0;
        aNode.flag=flag;
        for(int j=0;j<m;j++)
        {
            scanf("%d %d %d",&u,&v,&w);
            aNode.w=w;
            aNode.v=v;
            g[u].push_back(aNode);

        }
        flag=1;
        aNode.flag=flag;
        for(int j=0;j<k;j++)
        {
            scanf("%d %d %d",&u,&v,&w);
            aNode.w=w;
            aNode.v=v;
            g[u].push_back(aNode);

        }

        int ret=dijkstra(n,No);
        if(ret==-1)
            printf("Case %d: Impossible\n",i);
        else
            printf("Case %d: %d\n",i,ret);
    }

    return 0;
}

