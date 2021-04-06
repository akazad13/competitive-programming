#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 1010

#define Clear(a,b) memset(a,b,sizeof(a))

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

struct node
{
    int u,v,w;
    node(int a, int b, int c)
    {
        u=a;v=b;w=c;
    }
};

vector< node > G;
int d[Max];
vector<int> res,temp;

bool belmon_ford(int src,int N,int edge)
{
    int u,v,w;
    Clear(d,63);
    d[src]=0;
    bool Neg_cycle = false;
    bool update;

    for(int step=1;step<N;step++)
    {
        update=true;
        for(int i=0;i<edge;i++)
        {
            u = G[i].u; v = G[i].v; w = G[i].w;
            if(d[v]>d[u]+w)
            {
                update = false;
                d[v]=d[u]+w;
            }
        }
        if(update)
            break;
    }

    if(update)
        return 0;
    update=true;

    for(int i=0;i<edge;i++)
    {
        u = G[i].u; v = G[i].v; w = G[i].w;
        if(d[v]>d[u]+w)
        {
            temp.push_back(v);
            update = false;
            d[v]=d[u]+w;
        }
    }

    if(update)
        return 0;
    else
        return 1;
}

vector<int> rev[Max];

void rev_graph(int vertex,int edge)
{
    for(int i=0;i<=vertex;i++)
    {
        rev[i].clear();
    }
    int u,v;
    for(int i=0;i<edge;i++)
    {
        u = G[i].u;
        v = G[i].v;
        rev[u].push_back(v);
    }
    return ;
}


bool vis[Max];

void dfs(int u)
{
    vis[u]=1;

    for(int i=0;i<rev[u].size();i++)
    {
        int v = rev[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
    return ;
}

int main()
{
    int test;
    int u,v,w,vertex,edge,src,des;
    read(test);

    for(int Case =1 ;Case<=test; Case++)
    {
        read(vertex); read(edge);

        G.clear();
        res.clear();
        temp.clear();

        for(int i=0;i<edge;i++)
        {
            read(u); read(v); read(w);
            G.push_back(node(v,u,w));
        }

        src = vertex;

        for(int i=0;i<vertex;i++)
            G.push_back(node(src,i,0));

        bool ret = belmon_ford(src,vertex+1,edge+vertex);
        printf("Case %d:",Case);

        if(ret==0)
            printf(" impossible\n");
        else
        {
            Clear(vis,0);

            rev_graph(vertex,edge);

            int len = temp.size();
            for(int i=0;i<len;i++)
            {
                u = temp[i];
                if(vis[u]==0)
                {
                    dfs(u);
                }
            }

            for(int i=0;i<vertex;i++)
            {
                if(vis[i])
                    printf(" %d",i);
            }

            printf("\n");
        }
    }
    return 0;
}
