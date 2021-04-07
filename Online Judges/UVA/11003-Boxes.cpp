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

//End Macros

struct node
{
    int weight,hold;
};

int n,make;
node arr[1002];
int dp[1002][3010];

int M;

int solve(int ind, int Max)
{
    if(ind>=n)
    {
        return 0;
    }

    //cout<<Max<<endl;
    M = max(M,Max);

    if(dp[ind][Max]!=-1) return dp[ind][Max];

    int ret1=0;
    int ret2=0;

   // cout<<ind<<" "<<Max<<" "<<arr[ind].hold<<endl;

    if(Max<=arr[ind].hold )
    {
        if(Max+arr[ind].weight>=3000)
            ret1 = 1;
        else
            ret1 = solve(ind+1, Max+arr[ind].weight)+1;
    }

    ret2= solve(ind+1, Max);

   // cout<<ind<<" "<<ret1<<" "<<ret2<<endl;

    return dp[ind][Max]= max(ret1,ret2);
}

int main()
{
    //freopen("uvain.txt","r",stdin);
    //freopen("uvaout.txt","w",stdout);

    while(scanf("%d",&n)==1)
    {

        if(n==0) break ;

        for(int i=0;i<n;i++)
            scanf("%d %d",&arr[i].weight, &arr[i].hold);

        reverse(arr,arr+n);

        //cout<<arr[0].hold<<endl;

        //CLEAR(dp,-1);


        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=3009;j++)
            {
                dp[i][j]=-1;
            }
        }

        M=0;

        int ret = solve(0,0);

       // cout<<M<<endl;

        printf("%d\n",ret);
    }

    return 0;

}




