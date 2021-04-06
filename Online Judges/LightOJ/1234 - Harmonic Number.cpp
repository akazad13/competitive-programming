#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065

double dp[1000010];

int main()
{
    dp[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        dp[i]=dp[i-1]+(1/(i*1.0));
    }

    int test,n;
    READ(test);

    for(int i=1;i<=test;i++)
    {
        READ(n);
        if(n<=1000000)
            printf("Case %d: %.10f\n",i,dp[n]);
        else
        {
            printf("Case %d: %.10f\n",i,log(n+.5)+Gamma);
        }
    }

    return 0;

}
