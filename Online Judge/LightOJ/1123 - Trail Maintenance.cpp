#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 210
#define lld long long int
struct edge
{
    int u,v;
    int w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
int no;
int par[Max];
edge e[6010];

int findParent(int r)
{
    if( par[r] == r ) return r;

    return par[r] = findParent(par[r] );
}


int mst(int n)
{
    int number_of_Set;
    int total_cost;

    sort(e,e+no);

    for(int i=0;i<=n;i++)
        par[i]=i;

    int count=0;
    int m=-1;
    total_cost=0;

    for(int i=0;i<no;i++)
    {
        int u=findParent(e[i].u);
        int v=findParent(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            total_cost+=e[i].w;
        }
        else
        {
           m=i;
        }
    }

    if(m!=-1)
    {
        no--;
        e[m]=e[no];
    }
    if(count==n-1)
        return total_cost;
    else
        return -1;
}

int main()
{
    int n,ed,air_cost,test,u,v,w;
    cin>>test;
    for(int Case = 1; Case<=test ; Case++)
    {
        no=0;
        printf("Case %d:\n",Case);

        scanf("%d %d",&n,&ed);
        for(int i=1;i<=ed;i++)
        {
            scanf("%d %d %d",&e[no].u,&e[no].v,&e[no].w);
            no++;
            printf("%d\n",mst(n));
        }
    }
    return 0;
}
