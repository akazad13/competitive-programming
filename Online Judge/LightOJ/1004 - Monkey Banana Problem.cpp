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

int arr[202][102];
int dp[202][102];
int n;

int cal(int i,int j)
{
    if(i>2*(n-1)|| j<0 || j>=n)
        return 0;
    if(arr[i][j]==-1)
        return 0;
    if(dp[i][j]!=-1)  return dp[i][j];

    if(i<n-1)
    {
        dp[i][j] = arr[i][j]+max(cal(i+1,j),cal(i+1,j+1));
    }
    else
    {
        dp[i][j] = arr[i][j]+max(cal(i+1,j),cal(i+1,j-1));
    }
    return dp[i][j];
}

int main()
{
    int test;
    read(test);

    for(int Case = 1;Case<=test;Case++)
    {
        CLEAR(arr,-1);
        CLEAR(dp,-1);
        read(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                scanf("%d",&arr[n+i][j]);
            }
        }

        printf("Case %d: %d\n",Case,cal(0,0));
    }
    return 0;

}


