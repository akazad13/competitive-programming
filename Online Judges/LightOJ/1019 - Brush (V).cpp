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

vector<graph> g[2020];
int d[2020];

int dijkstra(int n)
{
    memset(d,63,sizeof(d));
    priority_queue <node,vector<node>, greater<node> > q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;

        if(u==n) return d[n];
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i].v;
            if(d[u]+ g[u][i].weight< d[v])
            {
                d[v]=d[u]+ g[u][i].weight;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int main(){

    int test;
    scanf("%d",&test);

    graph temp;

    for(int i=1;i<=test;i++)
    {
        for(int j=0;j<2020;j++)
            g[j].clear();

        int n,e,u,v,w;
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

        int ret=dijkstra(n);
        if(ret==-1)
            printf("Case %d: Impossible\n",i);
        else
            printf("Case %d: %d\n",i,ret);

    }
    return 0;
}
