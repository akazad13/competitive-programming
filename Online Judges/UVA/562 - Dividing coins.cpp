#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int coin[102];
int dp[102][25010];
int n, make;

int solve(int ind, int take)
{
    if(ind>=n)
        return 0;
    if(dp[ind][take]!=-1) return dp[ind][take];

    int ret1=0;
    int ret2=0;

    if(take+coin[ind]<=make)
        ret1 = solve(ind+1,take+coin[ind])+coin[ind];
    ret2 = solve(ind+1,take);


    return dp[ind][take]=max(ret1,ret2);

}

int main()
{
    int test;
    scanf("%d",&test);

    while(test--)
    {

        scanf("%d",&n);

        int sum=0;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
            sum+=coin[i];
        }
        make = sum/2;

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=make;j++)
            {
                dp[i][j]=-1;
            }
        }

        int ret = solve(0,0);
        //cout<<ret<<endl;

        printf("%d\n",(sum-2*ret));
    }



    return 0;
}

