#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int dis[2000];
bool visited[2000];

struct node
{
    int u;
    long long int w;
    node(int a, long long int b)
    {
        u=a;w=b;
    }

    bool operator > (node const &p)const
    {
        return w>p.w;
    }

};


int Dijkstra(int des,long long int time,vector<int> edge[],vector<long long int> cost[])
{
    priority_queue<node,vector<node>,greater<node>> Q;

    int ans=0;

    for (int i=0; i<=200; i++)
    {
        dis[i]=1000000000;
        visited[i]=0;
    }
    dis[des]=0;

    Q.push(node(des,0));

    while(!Q.empty())
    {
        node top = Q.top(); Q.pop();

        int u=top.u;



        if(visited[u]==1) continue;
           // cout<<u<<"   dis: "<<dis[u]<<endl;
           if(dis[u]<=time)
                ans++;
           visited[u]=1;


        for(int i=0;i<(int)edge[u].size();i++)
        {
            int v=edge[u][i];

            if(cost[u][i]+dis[u]<dis[v])
            {
                dis[v]= cost[u][i]+dis[u];
                Q.push(node(v,dis[v]));
            }
        }
    }

    return ans;

}



int main()
{
    int test;
    cin>>test;

    int n,des,E;
    long long int time;
    for(int i=1;i<=test;i++)
    {
        vector<int> edge[200];
        vector<long long int> cost [200];
       // memset(cost,63,sizeof(cost));
        cin>>n>>des>>time>>E;

        int u,v;
        long long int w;

        for(int i=0;i<E;i++)
        {
            cin>>u>>v>>w;
            edge[v].push_back(u);
            cost[v].push_back(w);

        }


        if(i>1)
            cout<<"\n";

        cout<<Dijkstra(des,time,edge,cost)<<endl;
    }

    return 0;
}
