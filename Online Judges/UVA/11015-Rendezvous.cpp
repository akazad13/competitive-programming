#include<iostream>
#include<bits/stdc++.h>

using  namespace std;
#define Max 30
#define lld long long int
#define INF 1e9+7

int G[Max][Max];

void Floyed_warshall(int vertex)
{
    for(int k=1;k<=vertex;k++)
    {
        for(int i=1; i<=vertex; i++)
        {
            for(int j=1;j<=vertex;j++)
            {
                if(G[i][j]>G[i][k]+G[k][j])
                {
                    G[i][j]=G[i][k]+G[k][j];
                }
            }
        }
    }
}

int main()
{
    int vertex,edge,u,v,w,Case=1,cost,min_cost,index;
    char name[Max][Max];

    while(scanf("%d %d",&vertex,&edge)==2)
    {
        if(!vertex && !edge)
            break;
        for(int i=1;i<=vertex;i++)
        {
            for(int j=1;j<=vertex;j++)
            {
                G[i][j]=INF;
            }
        }

        for(int i=1;i<=vertex;i++)
            G[i][i]=0;


        for(int i=0;i<vertex;i++)
        {
            scanf("%s",name[i]);
        }

        for(int i=0;i<edge;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u][v]=w;
            G[v][u]=w;
        }
        Floyed_warshall(vertex);

        min_cost=INF;
        index=0;
        for(int j=1;j<=vertex;j++)
        {
            cost=0;
            for(int i=1;i<=vertex;i++)
            {
                cost+=G[i][j];
            }
            if(min_cost>cost)
            {
                min_cost=cost;
                index = j;
            }
        }

        printf("Case #%d : %s\n",Case++,name[index-1]);
    }


    return 0;
}
