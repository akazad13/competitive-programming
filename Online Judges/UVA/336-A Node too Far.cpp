/* A K Azad
     CSE-13
     RUET.

*/


//Directed Graph............................

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 10000

int bfs(int src ,int TT,vector<int> edge[])
{
    queue<int>Q;
	Q.push(src);
	int visited[max]={0},level[max]={0};
	//int parent[max];
	visited[src]=1;
    level[src]=0;
    int res[max]={0};
    res[level[src]]++;
	while(!Q.empty())
	{
		int u=Q.front();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			if(!visited[v])
			{
				level[v]=level[u]+1;
				res[level[v]]++;
				//parent[v]=u;
				visited[v]=1;
				Q.push(v);

				//cout<<v<<" "<<level[v]<<endl;
			}
		}
		Q.pop();
	}

	int count=0;

	for(int i=0;i<=TT;i++)
    {
        count+=res[i];
    }
	//cout<<count<<endl;
	return count;
}



int main()
{
   // freopen("input.txt","r",stdin);

    int E;
    int nn=1;

    while(cin>>E,E)
    {

        vector<int> edge[max];
        map<int,int> myMap;

        int node=0;

        for(int i=1;i<=E;i++)
        {
            long long int n1,n2;
            cin>>n1>>n2;
            if(myMap[n1]==0)
            {
                node++;
                myMap[n1]=node;
            }
            if(myMap[n2]==0)
            {
                node++;
                myMap[n2]=node;
            }

            //cout<<myMap[n1]<<" "<<myMap[n2]<<endl;
            edge[myMap[n1]].push_back(myMap[n2]);
            edge[myMap[n2]].push_back(myMap[n1]);
        }

        //4cout<<"end of input"<<endl;

        long long int src;
        int  TT;

        while(cin>>src>>TT,src|TT)
        {
            if(myMap[src]==0)
            {
                printf("Case %d: %d nodes not reachable from node %lld with TTL = %d.\n",nn,node,src,TT);
                nn++;
                continue;
            }


            int count  = bfs(myMap[src],TT,edge);
           // cout<<count<<endl;

            printf("Case %d: %d nodes not reachable from node %lld with TTL = %d.\n",nn,(node-count),src,TT);
            nn++;
        }
        edge[max].clear();
        myMap.clear();
    }
    return 0;

}



