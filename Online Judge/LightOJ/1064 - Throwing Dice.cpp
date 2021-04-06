#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ul unsigned long long int

ul dp[30][150];
bool visited[30][150];
int make,n;

ul cal(int dice, int total)
{
    if(dice==n)
    {
        if(total>=make)
            return 1;
        else
            return 0;
    }

    if(visited[dice][total])  return dp[dice][total];

    ul ans=0;

    for(int i=1;i<=6;i++)
    {
        ans+=cal(dice+1,total+i);
    }

    dp[dice][total]=ans;
    visited[dice][total]=1;

    return dp[dice][total];
}

ul POW(int n)
{
    ul ans=1,p=6;
    for(int i=1;i<=n;i++)
    {
        ans=ans*p;
    }
    return ans;
}


int main()
{
    int test;
    ul space;
    scanf("%d",&test);

    for(int Case =1; Case<=test;Case++)
    {
        memset(dp,0,sizeof(dp));
        memset(visited,0,sizeof(visited));
        scanf("%d %d",&n,&make);
        ul ret = cal(0,0);

        space = POW(n);

        ul g = __gcd(ret,space);

        ret/=g;
        space/=g;

        if(space==1)
        {
            printf("Case %d: %llu\n",Case,ret);
        }
        else
        {
            printf("Case %d: %llu/%llu\n",Case,ret,space);
        }
    }
    return 0;
}
