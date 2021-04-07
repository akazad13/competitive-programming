#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define PA pair<int,int>
#define MP(a,b) make_pair(a,b)
#define Max 2010
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))


vector< PA > G;
int cost[Max];
int d[Max];

int belmon_ford(int src,int N,int edge)
{
    int u,v;
    Clear(d,INFINITY);
    d[src]=0;
    bool Neg_cycle = false;
    bool update;

    for(int step=1;step<=N;step++)
    {
        update=true;
        for(int i=0;i<edge;i++)
        {
            u = G[i].first; v = G[i].second;
            if(d[v]>d[u]+cost[i])
            {
                update = false;
                if(step==N)
                    Neg_cycle=true;
                d[v]=d[u]+cost[i];

            }
        }

        if(update)
            break;
    }

    if(Neg_cycle)
        return (-1*INT_MAX);
    else
        return 0;


}


int main()
{
    int test;
    int u,v,w,vertex,edge,src,des;
    read(test);

    for(int Case =1 ;Case<=test; Case++)
    {
        G.clear();
        read(vertex); read(edge);

        for(int i=0;i<edge;i++)
        {
            read(u); read(v); read(w);
            G.push_back(MP(u,v));
            cost[i]=w;
        }
        //read(src);
        //read(des);
        int res = belmon_ford(0,vertex,edge);
        if(res==(-1*INT_MAX))
            printf("possible\n");
        else
            printf("not possible\n");
    }




    return 0;
}
