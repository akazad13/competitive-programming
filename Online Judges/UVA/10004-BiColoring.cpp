/* A K Azad
     CSE-13
     RUET.

*/


//Directed Graph............................

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 210

bool bfs(vector<int> edge[],int n,int src)
{
    queue<int>Q;
    Q.push(src);
    int visited[max]={0};
    visited[src]=1;
    bool color[max]= {false};

    color[src]=true;

    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(!visited[v])
            {
                color[v]=(!color[u]);
                visited[v]=1;
                Q.push(v);
            }
            else
            {
                if(color[v]==color[u])
                {
                    return 0;
                }
            }
        }
        Q.pop();
    }

    return 1;

}



int main()
{
   // freopen("input.txt","r",stdin);

    int N,E;

    while(cin>>N,N)
    {
        cin>>E;

        vector<int> edge[max];

        for(int i=1;i<=E;i++)
        {
            int n1,n2;
            cin>>n1>>n2;
            edge[n1].push_back(n2);
            edge[n2].push_back(n1);
        }

        if(bfs(edge,N,1))
        {
            printf("BICOLORABLE.\n");
        }
        else
        {
            printf("NOT BICOLORABLE.\n");
        }

    }
        return 0;

}



