#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fx[]={+1,-1,+0,-0};
int fy[]={+0,-0,+1,-1};

bool grid[1002][1002];
int level[1050][1050];
int row,column;

#define valid(i,j) i>=0 && i<row && j>=0 && j<column
#define pii  pair<int ,int>
#define uu first
#define vv second

int bfs(int stX,int stY, int desX, int desY)
{
    grid[stX][stY]=1;

    memset(level,0,sizeof(level));

    queue<pii>myQueue;

    myQueue.push(pii(stX,stY));

    while(!myQueue.empty())
    {
        pii top = myQueue.front();
        myQueue.pop();

        if(top.uu==desX&&top.vv==desY)
            break;
        for(int i=0;i<4;i++)
        {
            int x= top.uu+fx[i];
            int y= top.vv+fy[i];

            if(valid(x,y)&&grid[x][y]!=1)
            {
                grid[x][y]=1;
                level[x][y]=level[top.uu][top.vv]+1;
                myQueue.push(pii(x,y));
            }
        }
    }

}

int main()
{
    //freopen("10653.txt","r",stdin);


    int n,rowNum,m,columNum,stX,stY,desX,desY;

    while(cin>>row>>column,row|column)
    {
        memset(grid,0,sizeof(grid));

        cin>>n;


        for(int i=0;i<n;i++)
        {

            cin>>rowNum>>m;

            for(int k=0;k<m;k++)
            {
                cin>>columNum;
                grid[rowNum][columNum]=1;
            }
        }

    /*    for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
                cout<<grid[i][j];
            cout<<"\n";
        }

        */

        cin>>stX>>stY;
        cin>>desX>>desY;
        //cout<<5<<endl;

        bfs(stX,stY,desX,desY);


        cout<<level[desX][desY]<<endl;


    }
    return 0;
}

