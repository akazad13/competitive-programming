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



int n,len;
int arr[55];
int dp[1002][1002];

int M;

int solve(int left, int Right)
{
    if(left>Right)
        return 0;

   // cout<<left<<" "<<Right<<endl;

    if(dp[left][Right]!=-1) return dp[left][Right];

    int ret=0;
    int ret1=1000000000;
    bool flag=0;

    for(int i=0;i<n;i++)
    {

        if(arr[i]>=left && arr[i]<Right)
        {
            flag=1;
           // cout<<left<<" "<<Right<<endl;
            ret1 = min(ret1,(solve(left,arr[i])+solve(arr[i]+1,Right)+(Right-left+1)));
           // cout<<ret1<<endl;
        }
    }

    if(flag==0)
        ret1=ret;


    return dp[left][Right]= ret1;
}

int main()
{
   // freopen("uvain.txt","r",stdin);
    //freopen("uvaout.txt","w",stdout);

    while(scanf("%d",&len)==1)
    {

        if(len==0) break ;

        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);


        for(int i=0;i<=len+1;i++)
        {
            for(int j=0;j<=len+1;j++)
            {
                dp[i][j]=-1;
            }
        }

        int ret = solve(1,len);

       //cout<<len<<endl;

        printf("The minimum cutting is %d.\n",ret);
    }

    return 0;

}





