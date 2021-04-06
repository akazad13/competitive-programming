//LCA

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 10100
#define pb push_back
#define inf 1000000000

#define ll long long int

vector<int> g[Max];
vector<int> rev[Max];


struct node
{
    int u;
    ll w;
    node(int a,ll b){u=a; w=b;}
    bool operator > ( const node& p ) const { return w > p.w; }
};

ll d[Max];

void dijkstra(int p)
{
    for(int i=0;i<Max;i++)
        d[i]=inf;

    priority_queue <node,vector<node>, greater<node> > q;

    q.push(node(p,0));
    d[p]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(d[u]+1 < d[v])
            {
                d[v]=d[u]+1;
                q.push(node(v,d[v]));
            }
        }
    }

    return ;
}


ll rr[Max];

void dijkstra1(int p)
{
    for(int i=0;i<Max;i++)
        rr[i]=inf;

    priority_queue <node,vector<node>, greater<node> > q;

    q.push(node(p,0));
    rr[p]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
        for(int i=0;i<(int)rev[u].size();i++)
        {
            int v=rev[u][i];
            if(rr[u]+1 < rr[v])
            {
                rr[v]=rr[u]+1;
                q.push(node(v,rr[v]));
            }
        }
    }

    return ;
}


int main()
{
    //freopen("in.txt","r",stdin);


    int n,test,e,st,q;
    int u,v,c;
    scanf("%d",&test);
    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d %d %d",&n,&e,&st,&q);

        for(int i=0;i<Max;i++)
        {
            g[i].clear();
            rev[i].clear();
        }

        for(int i=0;i<e;i++)
        {
            scanf("%d %d",&u,&v);
            g[u].pb(v);
            rev[v].pb(u);
        }

        dijkstra(st);
        dijkstra1(st);


        printf("Case %d:\n",Case);

        while(q--)
        {
            scanf("%d %d",&u,&v);

            ll res = rr[u] + d[v];

            if(res>=inf)
            {
                printf("Not possible to go from %d to %d.\n",u,v);
            }
            else
            {
                printf("The shortest distance from %d to %d is %lld.\n",u,v,res);
            }
        }
    }

    return 0;
}

