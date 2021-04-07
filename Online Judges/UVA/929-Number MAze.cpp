#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int row,column;
int grid[1010][1010];
int cost[1010][1010];
int fx[] = {+1,-1,+0,-0};
int fy[] = {+0,-0,+1,-1};

#define valid(i,j) i>=1 && i<=row && j>=1&&j<=column


struct node
{
    int x,y,w;
    node(int a,int b,int c)
    {
        x=a;y=b;w=c;
    }

    bool operator > (node const &p)const
    {
        return w>p.w;
    }
};

void Dijkstra()
{
    memset(cost,63,sizeof(cost));

    priority_queue<node, vector<node>, greater<node> > Q;

    Q.push(node(1,1,0));
    cost[1][1]=grid[1][1];

    while(!Q.empty())
    {
        node top = Q.front(); Q.pop();

        int x = top.x;
        int y = top.y;



        if(x==row && y==column)
            return ;
        for(int i=0;i<4;i++)
        {
            int xx  = x+fx[i];
            int yy  = y+fy[i];

            if(valid(xx,yy))
            {
                //cout<<4<<endl;
                int cost1 = grid[xx][yy];

                if(cost[x][y]+cost1<cost[xx][yy])
                {
                   // cout<<xx<< " : "<<yy<<"  "<<cost[x][y]+cost1<<" " <<grid[xx][yy]<<endl;
                    cost[xx][yy]= cost[x][y]+cost1;
                    Q.push(node(xx,yy,cost[xx][yy]));
                }
            }
        }
    }

}

int main()
{

   // freopen("output.txt","w",stdout);
    int test;

    cin>>test;

    while(test--)
    {
        memset(grid,63,sizeof(grid));

        cin>>row;
        cin>>column;

        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=column;j++)
            {
                cin>>grid[i][j];
            }
        }

       /* for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=column;j++)
            {
                cout<<grid[i][j]<<" ";
            }

            cout<<endl;
        }*/

        Dijkstra();

        cout<<cost[row][column]<<endl;
    }




    return 0;

}
