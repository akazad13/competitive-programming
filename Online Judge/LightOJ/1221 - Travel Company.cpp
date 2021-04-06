#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define Max 110
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
#define lld long long int

struct node
{
    int u,v;
    lld w;
    node(int a, int b, lld c)
    {
        u=a;v=b;w=c;
    }
};

vector< node > G;
lld d[Max];

int belmon_ford(int src,int N,int des,int edge)
{
    int u,v;
    lld w;
    Clear(d,INFINITY);

    d[src]=0;
    bool Neg_cycle = false;
    bool update;

    for(int step=1;step<=N;step++)
    {
        update=true;
        for(int i=0;i<edge;i++)
        {
            u = G[i].u; v = G[i].v; w = G[i].w;
            if(d[v]>d[u]+w)
            {
                update = false;
                if(step==N)
                    Neg_cycle=true;
                d[v]=d[u]+w;

            }
        }

        if(update)
            break;
    }

    if(Neg_cycle)
        return (-1*INT_MAX);
    else
        return d[des];
}


int main()
{
    int test;
    int u,v,vertex,edge;
    lld p,w,y;
    read(test);

    for(int Case =1 ;Case<=test; Case++)
    {
        read(vertex); read(edge);

        G.clear();

        scanf("%lld",&p);

        for(int i=0;i<edge;i++)
        {
            read(u); read(v);
            scanf("%lld %lld",&w,&y);
            G.push_back(node(u,v,y*p-w));
        }
        int res = belmon_ford(0,vertex,vertex,edge);
        if(res==(-1*INT_MAX))
            printf("Case %d: YES\n",Case);
        else
            printf("Case %d: NO\n",Case);
    }
    return 0;
}

