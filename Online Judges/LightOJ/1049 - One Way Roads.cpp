#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 110
vector<int> g[Max];
int cost[Max][Max];
int visited[Max],Tcost[Max];

int bfs(int src,int des)
{
    memset(visited,0,sizeof(visited));
    memset(Tcost,0,sizeof(Tcost));

	queue<int>Q;
	Q.push(src);
	visited[src]=1;
    Tcost[src]=0;

	while(!Q.empty())
	{
		int u=Q.front();
		if(u==des) return Tcost[u];
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(!visited[v])
			{
				Tcost[v]=Tcost[u]+cost[u][v];
				visited[v]=1;
				Q.push(v);
			}
		}
		Q.pop();
	}
}

int main()
{
    int N,test,u,v,w;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        for(int i=0;i<Max;i++)
            g[i].clear();
        memset(cost,0,sizeof(cost));
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(u==1)
            {
                cost[v][u]=w;
                g[u].push_back(v);
            }
            else if(v==1)
            {
                cost[v][u]=w;
                g[v].push_back(u);
            }
            else
            {
                cost[v][u]=w;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }

        int p,q;
        p=g[1][0];
        q=g[1][1];

        int ret1 = bfs(p,q)+cost[1][p]+cost[q][1];
        int ret2 = bfs(q,p)+cost[1][q]+cost[p][1];

        printf("Case %d: %d\n",Case,min(ret1,ret2));
    }
    return 0;
}




