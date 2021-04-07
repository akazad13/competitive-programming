#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 120000
int parent[max+10];
int visited[max+10];

void bfs(vector<int>edge[],int src,int desti)
{
    queue<int>Q;
    Q.push(src);
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    visited[src]=1;
    while(!Q.empty() && visited[desti]==0)
    {
        int u=Q.front();
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(!visited[v])
            {
                parent[v]=u;
                visited[v]=1;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int main()
{

    int n;
    int k=0;

    while(cin>>n)
    {
        vector<int> edge[max+10];
       // memset(edge,0,sizeof(edge));
        map<string,int>myMap;
        map<int,string>data;
        char str1[4],str2[4];

        int i=1;

        while(n--)
        {
            scanf("%s %s",str1,str2);

            if(myMap[str1]==0)
            {
                data[i]=str1;
                myMap[str1]=i;
                i++;
            }
            if(myMap[str2]==0)
            {
                data[i]=str2;
                myMap[str2]=i;
                i++;
            }

            edge[myMap[str1]].push_back(myMap[str2]);
            edge[myMap[str2]].push_back(myMap[str1]);

        }

        scanf("%s %s",str1,str2);

        int src = myMap[str1];
        int des = myMap[str2];

        bfs(edge,src,des);

        if(k>0)
            cout<<"\n";

        if(parent[des]==0)
            cout<<"No route\n";
        /*else
        {
            printRoute(data,myMap[str2]);
        }*/

        else
        {
            int arr[max+10]={0};

            int node = des;

            int i=1;

            while(parent[node]>=1)
            {
               arr[i++]=node;
               arr[i++]=parent[node];
               node  = parent[node];
            }

            int len = i-1;

            for(int i = len;i>=1;i-=2)
            {
                cout<<data[arr[i]]<< " "<<data[arr[i-1]]<<endl;
            }
        }
        k++;
        data.clear();
        myMap.clear();


    }
    return 0;
}

