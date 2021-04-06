//1029 - Civil and Evil Engineer
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 520
vector<int> g[mx],cost[mx],subgraph[mx],cost_sub[mx];

struct node
{
    int u,v;
    long long int w;
    node(int a,int c,long long int b){u=a,v=c; w=b;}
    bool operator > ( const node& p ) const { return w > p.w;}
    bool operator < ( const node& p ) const { return w < p.w;}
};


bool visited[mx];

long long int min_cost=0,max_cost=0;
long long int MST_primes(int nn,int max_node)
{

    long long int p;
    min_cost=0;max_cost=0;
    memset(visited,false,sizeof(visited));
    priority_queue <node,vector<node>, greater<node> > q1;
    priority_queue <node,vector<node>, less<node> > q2;
   int u;
   int src=nn;
    for(int i=0;i<max_node;i++)
    {
        if(visited[src]==false)
        {
            u=i;
            visited[src]=true;
            for(int j=0;j<g[src].size();j++)
            {
                q1.push(node(src,g[src][j],cost[src][j]));
            }
            do
            {
                if(q1.empty())
                    break;
                node top = q1.top();
                src = top.v;
                u = top.u;
                p = top.w;
                q1.pop();
            } while(visited[src]==true && !q1.empty());



            if(visited[src]==false)
            {
                min_cost+=p;

            }

        }
    }

    memset(visited,0,sizeof(visited));
    src=nn;

    for(int i=0;i<max_node;i++)
    {
        if(visited[src]==false)
        {
            u=i;
            visited[src]=true;
            for(int j=0;j<g[src].size();j++)
            {
                q2.push(node(src,g[src][j],cost[src][j]));
            }
            do
            {
                if(q2.empty())
                    break;
                node top = q2.top();
                src = top.v;
                u = top.u;
                p = top.w;
                q2.pop();
            } while(visited[src]==true && !q2.empty());



            if(visited[src]==false)
            {
                visited[u]=true;
                max_cost+=p;

            }
        }
    }
}

int main()
{
    int u,v,w,n,e,test,des;
    cin>>test;
    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }

        while(scanf("%d %d %d",&u,&v,&w)==3)
        {
            if(u==0 && v==0 &&w==0)
                break;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);

        }

        MST_primes(0,n);
        printf("Case %d: ",Case);

        long long int res = min_cost+max_cost;

        if(res%2==0)
            printf("%lld\n",res/2);
        else
            printf("%lld/2\n",res);
    }
    return 0 ;
}
