#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 60
#define lld long long int
struct edge
{
    int u,v;
    long long int w;
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

int number_of_Set;
long long int total_cost;


lld mst(int n)
{
    sort(e.begin(),e.end());
    number_of_Set=n;
    for(int i=1;i<=n;i++)par[i]=i;

    int count=0;
    total_cost=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=findParent(e[i].u);
        int v=findParent(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            --number_of_Set;
            count++;
            total_cost+=e[i].w;
            if(count==n-1) break;
        }
    }
    if(count==n-1)
        return total_cost;
    return -1;
}

int main(){
     int n,test;
     lld w;
     lld total;
    cin>>test;
    for(int Case = 1; Case<=test ; Case++)
    {
        total=0;
        e.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%lld",&w);
                total+=w;
                if(i==j)
                    continue;
                if(w>0)
                {
                    edge data;
                    data.u=i;
                    data.v=j;
                    data.w=w;
                    e.push_back(data);
                }
            }
        }

        printf("Case %d: ",Case);
        lld ret = mst(n);
        if(ret==-1)
            printf("-1\n");
        else
            printf("%lld\n",total-ret);

    }
    return 0;
}
