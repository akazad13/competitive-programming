#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fx[]={+1,-1,+0,-0};
int fy[]={+0,-0,+1,-1};

int grid[30][30];
int row,column,n,x,y,startX,startY;


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

void bfs()
{
    queue<node> Q;
    Q.push(node(startX,startY));

    grid[startX][startY]=1;

    while(!Q.empty())
    {
        node p = Q.front(); Q.pop();

        for(int i=0;i<4;i++)
        {
            int xx = p.x+fx[i];
            int yy = p.y+fy[i];

            if(valid(xx,yy) && grid[xx][yy]==0)
            {
                grid[xx][yy]=1;
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
        scanf("%d %d",&column,&row);

        for(int j=0;j<row;j++)
            cin>>str[j];
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<column;k++)
            {
                if(str[j][k]=='#')
                    grid[j][k]=-1;
                else if(str[j][k]=='@')
                {
                    startX=j;
                    startY=k;
                }
            }
        }

        bfs();

        int count=0;

        for(int j=0;j<row;j++)
        {
            for(int k=0;k<column;k++)
            {
                if(grid[j][k]==1)
                    count++;
            }
        }
        printf("Case %d: %d\n",i,count);
    }

    return 0;
}

