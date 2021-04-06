#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 1002
#define rep(i,p,n) for( i = p; i<n;i++)

bool graph[Max][Max];
int color[Max];


bool safe(int v,int chosen_color,int vertex)
{
    int i,j;
    rep(i,0,vertex)
    {
        if(graph[v][i] && chosen_color == color[i])
            return false;
    }
    return true;
}

void solve(int v, int No_color, int vertex)
{

    if(v>vertex)
        return ;
    int i;
    rep(i,1,No_color+1)
    {
        if(safe(v,i,vertex))
        {
            //cout<<v<<endl;
            color[v]=i;
            solve(v+1,No_color,vertex);
            break ;
        }
    }
}

int main()
{

    int No_color,i;
    int vertex, edge,u,v,test;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        memset(graph,false,sizeof(graph));
        memset(color,0,sizeof(color));
            scanf("%d %d",&vertex,&edge);

            rep(i,0,edge)
            {
                scanf("%d %d",&u,&v);
                graph[u][v]=true;
                graph[v][u]=true;

            }


           solve(0,1000,vertex);

            int Maxi=0;

            for(int i=1;i<=vertex;i++)
            {
                Maxi = max(Maxi,color[i]);
            }

            if(Maxi==1)
                Maxi=0;

            printf("Case %d: %d\n",Case,Maxi);
    }


    return 0;
}

