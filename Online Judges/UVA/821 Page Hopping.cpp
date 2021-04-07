#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 102
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
const int INF = 1e8 + 7;


int G[Max][Max];

void Floyed_Warshall(int vertex)
{

    for(int k=1;k<=vertex;k++)
    {
        for(int i=1;i<=vertex;i++)
        {
            for(int j=1;j<=vertex;j++)
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
   // freopen("1.txt","r",stdin);
    //freopen("outt.txt","w",stdout);

    int test,u,v,Case=1,make;

    while(scanf("%d %d",&u,&v)==2)
    {
        int cnt=0;
        if(!u && !v)
        {
            break;
        }

        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                G[i][j]=INF;
               // cout<<G[i][j]<<endl;
            }
        }

        //cout<<G[1][1]<<endl;

        for(int i=0;i<=100;i++)
            G[i][i]=0;

        do
        {

            G[u][v]=1;
            //cout<<G[u][v]<<endl;
        }while(scanf("%d %d",&u,&v)==2 && (u ||v));

       // cout<<u<<" "<<v<<endl;

      // cout<<cnt<<endl;

        Floyed_Warshall(100);

        double Cost=0;

        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(G[i][j]!=INF && i!=j)
                {
                    Cost+=G[i][j];
                    cnt++;
                }
            }
        }

      //  cout<<Cost<<endl;


        double res = Cost/(cnt*1.0);

        printf("Case %d: average length between pages = %.3f clicks\n",Case++,res);



    }



    return 0;
}

