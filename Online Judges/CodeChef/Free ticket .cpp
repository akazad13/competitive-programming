//https://www.codechef.com/INOIPRAC/problems/INOI1402

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 230
#define Clear(a,b) memset(a,b,sizeof(a))
#define INF 1000000000

int G[Max][Max];
int u,v,w,n,e;

void Floyed_Warshall()
{

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(G[i][j]>G[i][k]+G[k][j])
                {
                    {
                        G[i][j]=G[i][k]+G[k][j];
                    }
                }
            }
        }
    }
}


int main()
{
    //freopen("in.txt","r",stdin);


    scanf("%d %d",&n,&e);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=INF;
        }
    }

    for(int i=0;i<n;i++)
        G[i][i]=0;

    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        G[u][v]=w;
        G[v][u]=w;
    }

    Floyed_Warshall();

    priority_queue<int> Q;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
          //  cout<<i<<" "<<j<<" "<<G[i][j]<<endl;
            Q.push(G[i][j]);
        }
    }

    printf("%d\n",Q.top());


    return 0;
}
