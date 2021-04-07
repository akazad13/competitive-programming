#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int u,v,w;
    node(int a,int b,int c)
    {
        u = a; v = b; w = c;
    }
};

#define Max 210
#define Clear(a,b) memset(a,b,sizeof(a))
#define read(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
const int INF = 1e8 + 7;


vector< node > G;
int d[Max];

void belmon_ford(int src, int N)
{
    int u,v,w;
   for(int i=0;i<=Max;i++)
        d[i]=INF;

    d[src]=0;

    for(int step=1;step<N;step++)
    {
        bool update = true;
        for(int i=0;i<G.size();i++)
        {
            u = G[i].u; v = G[i].v; w = G[i].w;
            if(d[v]>d[u]+w && d[u]!=INF)
            {
                update=false;
                d[v]=d[u]+w;
            }
        }
        if(update)
            break;
    }

    for(int i=0;i<G.size();i++)
    {
        u = G[i].u; v = G[i].v; w = G[i].w;
        if(d[v]>d[u]+w && d[u]!=INF)
        {
            d[v]=-1*INF;
        }
    }

    return ;
}

int main()
{
    //freopen("1.txt","r",stdin);
    int Case=1;
    int u,v,w,n,edge,q,p;
    int arr[Max];

    while(read(n)==1)
    {
        G.clear();
        for(int i=1;i<=n;i++)
        {
            read(arr[i]);
        }
        read(edge);

        for(int i=0;i<edge;i++)
        {
            read(u); read(v);
            w =(arr[v]-arr[u])*(arr[v]-arr[u])*(arr[v]-arr[u]);
            G.push_back(node(u,v,w));
        }

        belmon_ford(1,n);
        read(q);

        printf("Set #%d\n",Case++);

        for(int i=0;i<q;i++)
        {
            read(p);
            if(d[p]<3 || d[p]==INF)
                printf("?\n");
            else
                printf("%d\n",d[p]);
        }

    }
    return 0;
}
