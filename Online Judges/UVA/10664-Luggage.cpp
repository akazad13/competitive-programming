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

int n,make;
int arr[22];
int dp[22][110];

int solve(int ind, int take)
{
    if(ind>=n)
    {
        if(take==make)
            return 1;
        else
            return 0;
    }

    if(dp[ind][take]!=-1) return dp[ind][take];

    bool ret1=0;
    bool ret2=0;

    if(take+arr[ind]<=make)
    {
        ret1 = solve(ind+1, take+arr[ind]);
    }

    ret2= solve(ind+1, take);

    return dp[ind][take]= ret1|ret2;
}

int main()
{
    //freopen("uvain.txt","r",stdin);
    //freopen("uvaout.txt","w",stdout);
    int test,a;
    scanf("%d",&test);
    char ch = getchar();

    while(test--)
    {
        n=0;
        int sum=0;

        while(scanf("%d",&a)==1)
        {
            arr[n++] = a;
            sum+=a;
            char ch = getchar();

            if(ch=='\n')
                break;
        }

        if(sum%2)
        {
            printf("NO\n");
            continue;
        }

        make = sum/2;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=make;j++)
            {
                dp[i][j]=-1;
            }
        }

        bool ret = solve(0,0);

        if(ret)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;

}



