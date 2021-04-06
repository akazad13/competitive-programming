#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define READ(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long int
#define MOD 10056
int dp[1005][1005];
lld res[1010];

int main()
{
    CLEAR(dp,0);
    CLEAR(res,0);
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;

    for(int i=2;i<=1001;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j)
                dp[i][j]=1;
            else
            {
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
            }
        }
    }

    res[0]=1;
    res[1]=1;

    for(int i=2;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            res[i]+=(dp[i][j]*res[i-j])%MOD;
        }
    }

    int test,n;
    READ(test);

    for(int Case=1;Case<=test;Case++)
    {
        READ(n);
        printf("Case %d: %lld\n",Case,res[n]%MOD);
    }
    return 0;

}
