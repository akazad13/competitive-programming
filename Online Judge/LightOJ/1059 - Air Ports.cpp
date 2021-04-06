#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 60
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
int par[Max];
vector<edge>e;
int findParent(int r)
{
    if( par[r] == r ) return r;

    return par[r] = findParent(par[r] );
}

lld mst(int n,int air_cost)
{
    int number_of_Set;
    long long int total_cost;
    sort(e.begin(),e.end());
    number_of_Set=n;
    for(int i=1;i<=n;i++)
        par[i]=i;

    int count=0;
    total_cost=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=findParent(e[i].u);
        int v=findParent(e[i].v);
        if(u!=v)
        {
            if(air_cost>e[i].w)
            {
                par[u]=v;
                --number_of_Set;
                count++;
                total_cost+=e[i].w;
            }

            if(count==n-1) break;
        }
    }

    printf("%lld %d\n",total_cost+(number_of_Set*air_cost),number_of_Set);
}

int main(){
     int n,ed,air_cost,test,u,v,w;
    cin>>test;
    for(int Case = 1; Case<=test ; Case++)
    {
        e.clear();
        scanf("%d %d %d",&n,&ed,&air_cost);
        for(int i=1;i<=ed;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edge data;
            data.u=u;
            data.v=v;
            data.w=w;
            e.push_back(data);
        }

        printf("Case %d: ",Case);
        mst(n,air_cost);

    }

    return 0;

}
