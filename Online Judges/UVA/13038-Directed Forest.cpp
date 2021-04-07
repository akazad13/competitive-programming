#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool inDeg[100010];
int level[100010];
bool visited[100010];

vector<int> G[100010];

int bfs(int n,int src)
{
    int maximum=-11;
	queue<int>Q;
	Q.push(src);
	memset(level,0,sizeof(level));
	memset(visited,0,sizeof(visited));
	visited[src]=1;
    level[src]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			//if(!visited[v])
			//{
			    //cout<<v<<endl;
				level[v]=level[u]+1;
				//parent[v]=u;
				visited[v]=1;
				Q.push(v);
			//}
		}
		Q.pop();
	}

	for(int i=1;i<=n;i++)
    {
        if(maximum<level[i])
            maximum=level[i];
    }

    return maximum;
}

int main()
{
    int test,node,edge,u,v;
    cin>>test;

    for(int k=1;k<=test;k++)
    {
        //G[0].clear();
        memset(inDeg,0,sizeof(inDeg));
        scanf("%d %d",&node,&edge);

        for(int i=0;i<=node;i++)
            G[i].clear();

        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&u,&v);
            inDeg[v]=true;
            G[u].push_back(v);
        }

        for(int i=1;i<=node;i++)
        {
            if(inDeg[i]==false)
            {
               // cout<<i<<endl;
                G[0].push_back(i);
            }
        }

        printf("Case %d: %d\n",k,bfs(node,0));
       // G[0].clear();
    }


    return 0;

}

