#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define CLEAR(a,n) memset(a,n,sizeof(a))
#define Max 110
vector<int> g[Max];
int cost1[Max],cost2[Max];
bool visited[Max];

void bfs(int src,int destination,bool flag)
{
    queue<int>Q;
    CLEAR(visited,false);
    CLEAR(cost2,0);

	Q.push(src);
	visited[src]=true;
    cost2[src]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		if(flag && u==destination) break;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(!visited[v])
			{
				cost2[v]=cost2[u]+1;
				visited[v]=true;
				Q.push(v);
			}
		}
		Q.pop();
	}
}



int main()
{
    int test,node,edge,u,v;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        CLEAR(cost1,0);
        scanf("%d %d",&node,&edge);

        for(int i=0;i<=node;i++)
            g[i].clear();

        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d %d",&u,&v);

        bfs(u,v,false);
        for(int i=0;i<node;i++)
        {
            cost1[i]=cost2[i];
        }

        int MAX=-1;
        for(int i=0;i<node;i++)
        {
            bfs(i,v,true);
            if(cost2[v]+cost1[i]>MAX)
                MAX=cost2[v]+cost1[i];
        }

        printf("Case %d: %d\n",Case,MAX);
    }
    return 0;
}



