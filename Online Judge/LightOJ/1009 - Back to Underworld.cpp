#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//Directed Graph............................

int ind;
map<int,int> myMap;

#define mx 100010
vector<int> g[mx];
bool visited[mx];
bool color[mx];

int getMap(int n)
{
    if(myMap[n]==0)
    {
        myMap[n]=ind;
        ind++;
    }
    return myMap[n];
}

int bfs(int src)
{
    int max_red=0,max_green=0;
	queue<int>Q;
	Q.push(src);
	visited[src]=true;
    color[src]=true;
    max_green++;
	while(!Q.empty())
	{
		int u=Q.front();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(!visited[v])
			{
				visited[v]=true;
				color[v]=color[u]^1;
				if(color[v]==false)
                    max_red++;
                else
                    max_green++;
				Q.push(v);
			}
		}
		Q.pop();
	}
	return max(max_red,max_green);
}

int main()
{
    int test,edge,u,v,p,q,res;

    scanf("%d",&test);
    for(int Case =1;Case<=test; Case++)
    {
        for(int i=0;i<=ind;i++)
            g[i].clear();
        ind=1;
        myMap.clear();
        CLEAR(visited,false);
        CLEAR(color,false);
        res=0;

        scanf("%d",&edge);

        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&p,&q);
            int u=getMap(p);
            int v=getMap(q);

            g[u].push_back(v);
            g[v].push_back(u);
        }


        for(int i=1;i<ind;i++)
        {
            if(!visited[i])
            {
                res+=bfs(i);
            }
        }
        printf("Case %d: %d\n",Case,res);
    }

    return 0;

}




