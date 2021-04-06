#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[102][102];
int arr[101];
int n,k;

#define inf 100000000

int solve(int ind, int wt)
{
    if(ind>=k)
    {
        //if(take==n && wt==k)
        //    return 0;
        //else
        if(wt==k)
            return 0;
        else
            return inf;
    }
    if(dp[ind][wt]!=-1) return dp[ind][wt];

    //cout<<ind<<endl;

    int ret1 = inf;
    int ret2 = inf;

    if(wt+(ind+1)<=k && arr[ind]!=-1)
    {
        ret1 = solve(ind,wt+(ind+1))+arr[ind];
    }

    ret2=solve(ind+1,wt);
    dp[ind][wt] = min(ret1,ret2);

    return dp[ind][wt];
}

int main()
{

    int test;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&k);

        /*for(int i=0;i<=k+1;i++)
        {
            for(int j=0;j<=n+1;j++)
            {
                for(int l=0;l<=k+1;l++)
                {
                    dp[i][j][l]=-1;
                }
            }
        }*/

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<k;i++)
        {
            scanf("%d",&arr[i]);
        }


        int ret = solve(0,0);
        if(ret==inf)
            printf("-1\n");
        else
            printf("%d\n",ret);

    }
    return 0;
}
