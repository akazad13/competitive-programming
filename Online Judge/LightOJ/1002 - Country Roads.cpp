#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct graph
{
    int v;
    int weight;
};

struct node
{
    int u;
    long long int w;
    node(int a,long long int b){u=a; w=b;}
    bool operator > ( const node& p ) const { return w > p.w; }
};

vector<graph> g[50000];
int d[50000];

int dijkstra(int src,int des)
{
    memset(d,63,sizeof(d));
    int max=40000;
    priority_queue <node,vector<node>, greater<node> > q;
    q.push(node(src,0));

    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;

        if(u==des) return d[des];
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i].v;
            if(d[u]<= g[u][i].weight)
            {
                d[v]=d[u];
                q.push(node(v,d[v]));
            }
            else
            {
                d[v]=d[u];
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int main()
{
    int test;
    scanf("%d",&test);

    graph temp;

    for(int i=1;i<=test;i++)
    {
        for(int j=0;j<50000;j++)
            g[j].clear();

        int n,e,u,v,w,t;
        scanf("%d %d",&n,&e);
        for(int i=0;i<e;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            temp.v=v;
            temp.weight=w;
            g[u].push_back(temp);
            temp.v=u;
            g[v].push_back(temp);
        }

        scanf("%d",&t);
        printf("Case %d:\n",i);

        for(int k=0;k<n;k++)
        {
            int ret=dijkstra(k,t);
            if(ret==-1)
                printf("Impossible\n");
            else
                printf("%d\n",ret);
        }
    }
    return 0;
}

