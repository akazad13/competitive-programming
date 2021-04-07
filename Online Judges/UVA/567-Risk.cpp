/* A K Azad
     CSE-13
     RUET.

*/


//Directed Graph............................

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 1000

int bfs(int src ,int desti,vector<int> edge[])
{
    queue<int>Q;
    Q.push(src);
    int visited[max]={0},level[max]={0};
    //int parent[max];
    visited[src]=1;
    level[src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(!visited[v])
            {
                level[v]=level[u]+1;
                visited[v]=1;
                Q.push(v);

                //cout<<v<<" "<<level[v]<<endl;
            }
        }

        if(level[desti]!=0)
        {
            return level[desti];
        }
        Q.pop();
    }



    return 0;
}



int main()
{
   // freopen("input.txt","r",stdin);

    int E,n,node;
    int test=1;

    while(cin>>n)
    {
        vector<int> edge[max];
       // map<int,int> myMap;

        for(int i=0;i<n;i++)
        {
            cin>>node;
            edge[1].push_back(node);
            edge[node].push_back(1);

        }

        for(int i=2;i<=19;i++)
        {
            cin>>n;
            for(int j=0;j<n;j++)
            {
                cin>>node;
                edge[i].push_back(node);
                edge[node].push_back(i);

            }
        }

        cout<<"Test Set #"<<test<<"\n";


        int quary;
        int  src,desti;

        cin>>quary;

        while(quary--)
        {
            cin>>src>>desti;
            int path = bfs(src,desti,edge);

            printf("%2d to %2d: %d\n",src,desti,path);


        }
        edge[max].clear();

        test++;
        cout<<"\n";
        //myMap.clear();
    }
    return 0;

}





