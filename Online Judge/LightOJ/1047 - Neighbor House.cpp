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

int arr[22][3];
int dp[22][3];
int n;

int cal(int i,int j)
{
    if(i==n)
        return 0;
    if(i>=n|| j<0 || j>2)
        return INT_MAX;

    if(dp[i][j]!=-1)  return dp[i][j];

    for(int k=0;k<3;k++)
    {
        dp[i][k]= arr[i][k]+min(min( cal(i+1,k+1) , cal(i+1,k-1) ), min( cal(i+1,k+2) , cal(i+1,k-2) ));
    }
    return dp[i][j];
}

int main()
{
    int test;
    read(test);

    for(int Case = 1;Case<=test;Case++)
    {
        CLEAR(dp,-1);
        read(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        int ret = cal(0,0);

        for(int i=0;i<3;i++)
            ret = min(ret,dp[0][i]);

        printf("Case %d: %d\n",Case,ret);
    }
    return 0;
}



