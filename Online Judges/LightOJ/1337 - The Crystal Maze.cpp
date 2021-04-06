#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

#define Max 505
char str[Max][Max];
bool grid[Max][Max];
int RES[Max][Max];
int m,n;

#define valid(a,b) a>=0 && a<m && b>=0 && b<n
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

struct node
{
    int x;
    int y;
    node(int a,int b)
    {
        x=a;y=b;
    }
};


void bfs_grid(int p,int q)
{
    int res=0;

    queue<node> Q,Q1;
    Q.push(node(p,q));

    grid[p][q]=true;

    while(!Q.empty())
    {
        node data = Q.front();
        Q1.push(data); Q.pop();

        for(int i=0;i<4;i++)
        {
            int xx = data.x+fx[i];
            int yy = data.y+fy[i];

            if(valid(xx,yy) && grid[xx][yy]==false)
            {
                if(str[xx][yy]=='.' || str[xx][yy]=='C')
                {
                    if(str[xx][yy]=='C')
                        res++;

                    grid[xx][yy]=true;
                    Q.push(node(xx,yy));
                }
            }
        }
    }
    while(!Q1.empty())
    {
        node data = Q1.front(); Q1.pop();
        RES[data.x][data.y]=res;
    }
}


int main()
{
    int test,query,x,y;

    read(test);
    for(int Case = 1; Case<=test; Case++)
    {
        CLEAR(grid,false);
        CLEAR(RES,-1);
        read(m);read(n);read(query);
        char ch = getchar();

        for(int i=0;i<m;i++)
        {
            scanf("%s",str[i]);
        }

        printf("Case %d:\n",Case);

        while(query--)
        {
            read(x);read(y);
            x--;y--;

            if(RES[x][y]!=-1)
            {
                printf("%d\n",RES[x][y]);
            }
            else
            {
                bfs_grid(x,y);
                printf("%d\n",RES[x][y]);

            }
        }
    }

    return 0;

}


