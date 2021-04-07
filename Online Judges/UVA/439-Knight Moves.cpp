#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fx[]={+1,+1,-1,-1,+2,+2,-2,-2};
int fy[]={+2,-2,+2,-2,+1,-1,+1,-1};

bool grid[10][10];
int level[100][100];
int row=8,column=8;

#define valid(i,j) i>=1 && i<=row && j>=1 && j<=column
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
        for(int i=0;i<8;i++)
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
    char str1[3],str2[3];

    while(scanf("%s %s",str1,str2)==2)
    {
        memset(grid,0,sizeof(grid));

        stX = str1[0]-'a'+1;
        stY = str1[1]-'0';
        desX = str2[0]-'a'+1;
        desY = str2[1]-'0';

        //cout<<stX<< " "<<stY<< " "<<desX<< " "<<desY<<endl;

        bfs(stX,stY,desX,desY);


        cout<<"To get from "<<str1<<" to "<<str2<<" takes ";


        cout<<level[desX][desY];
        cout<<" knight moves.\n";


    }
    return 0;
}



