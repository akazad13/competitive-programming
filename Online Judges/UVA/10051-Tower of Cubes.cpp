#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[502][6];
int n;

int dp[502][102];
int dir[502][102];

int solve(int ind, int col)
{

    if(ind>=n)
        return 0;

    if(dp[ind][col]!=-1) return dp[ind][col];

    int ret1=0;
    int ret2=0;
    int ret3=0;
    int color;
    int top;

    int in=-2;

    for(int i=0;i<6;i++)
    {
        if(col==0)
        {

            if(i%2==0)
            {
                //top = arr[ind][i];
                color  = arr[ind][i+1];
            }
            else
            {
                //top = arr[ind][i];
                color = arr[ind][i-1];
            }

            ret1 = solve(ind+1,color)+1;
        }
        else if(arr[ind][i]==col)
        {
            if(i%2==0)
            {
                //top = arr[ind][i];
                color  = arr[ind][i+1];
            }

            else
            {
                //top = arr[ind][i];
                color = arr[ind][i-1];
            }

            ret1 = solve(ind+1,color)+1;

        }

        //ret3 = max(ret1,ret3);
        if(ret1>ret3)
        {
           // in = top;
           in  = i;
            ret3 = ret1;
        }

    }

    ret2 = solve(ind+1,col);

    if(ret3>=ret2)
    {
        //cout<<ind<<" "<<col<<" "<<in<<endl;
        dir[ind][col]=in;
    }

    else
    {
        dir[ind][col]=-2;
    }

    return dp[ind][col] = max(ret3,ret2);
}

void print(int bottom)
{
    if(bottom==1)
        printf("back\n");
    else if(bottom==0)
        printf("front\n");
    else if(bottom==3)
        printf("right\n");
    else if(bottom==2)
        printf("left\n");
    else if(bottom==5)
        printf("bottom\n");
    else if(bottom==4)
        printf("top\n");

}

void printSol(int res)
{
    int col=0;
    int i=0;

    while(dir[i][col]!=-1 && i<n)
    {
        //cout<<dir[i][col]<<endl;
        if(dir[i][col]==-2)
        {
            i++;
        }
        else
        {
            printf("%d ",i+1);
            print(dir[i][col]);
            //i++;

            if(dir[i][col]%2==0)
                dir[i][col]+=1;
            else
                dir[i][col]-=1;

            col=arr[i][dir[i][col]];
            i++;
        }
    }

    return ;
}

int main()
{
    //freopen("uvain.txt","r",stdin);
    //freopen("uvaout.txt","w",stdout);
    bool flag=0;
    int cnt=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d %d %d %d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3],&arr[i][4],&arr[i][5]);
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=100;j++)
            {
                dp[i][j]=-1;
                dir[i][j]=-1;
            }
        }

        if(flag)
            printf("\n");
        flag=1;

        int res=0;
        res  = solve(0,0);


        printf("Case #%d\n",cnt++);
        printf("%d\n",res);

        printSol(res);

    }


    return 0;
}
