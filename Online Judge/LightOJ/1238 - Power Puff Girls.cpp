#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fx[]={+1,-1,+0,-0};
int fy[]={+0,-0,+1,-1};

int grid[30][30],pos[5][5],cost[30][30];
int row,column,desX,desY;


#define valid(x,y) x>=0 && x<row && y>=0 && y<column

struct node
{
    int x;
    int y;
    node(int a,int b)
    {
        x=a;y=b;
    }
};

int bfs(int con,int x,int y)
{
    memset(cost,0,sizeof(cost));
    queue<node> Q;
    Q.push(node(x,y));

    grid[x][y]=1;
    cost[x][y]=0;

    while(!Q.empty())
    {
        node p = Q.front(); Q.pop();

        if(p.x==desX && p.y==desY)
            return cost[p.x][p.y];

        for(int i=0;i<4;i++)
        {
            int xx = p.x+fx[i];
            int yy = p.y+fy[i];

            if(valid(xx,yy) && grid[xx][yy]>=0 && grid[xx][yy]<=con)
            {
                grid[xx][yy]=1+con;
                cost[xx][yy]= cost[p.x][p.y]+1;

                Q.push(node(xx,yy));
            }
        }
    }
}

int main()
{
    string str[30];
    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        memset(grid,0,sizeof(grid));
        scanf("%d %d",&row,&column);

        for(int j=0;j<row;j++)
            cin>>str[j];

        int in=0;

        for(int j=0;j<row;j++)
        {
            for(int k=0;k<column;k++)
            {
                if(str[j][k]=='#' || str[j][k]=='m')
                    grid[j][k]=-1;
                else if(str[j][k]=='.')
                {
                    grid[j][k]=0;
                }
                else if(str[j][k]=='h')
                {
                    desX=j;
                    desY=k;
                }
                else
                {
                    pos[in][0]=j;
                    pos[in][1]=k;
                    in++;
                }
            }
        }


        int step=0;

        for(int ind=0;ind<in;ind++)
        {
           int step1 = bfs(ind,pos[ind][0],pos[ind][1]);
           if(step1>step)
            step=step1;
        }
        printf("Case %d: %d\n",i,step);
    }

    return 0;
}


