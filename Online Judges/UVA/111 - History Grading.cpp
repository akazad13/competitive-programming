#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int a[22],b[22];
int dp[22][22];
int n;

int solve()
{
    memset(dp,0,sizeof(dp));

    //dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

   /* for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return dp[n][n];
}

int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   int p;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&p);
        a[p-1]=i;
    }

    while(scanf("%d",&p)==1)
    {
        b[p-1]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&p);
            b[p-1]=i;
        }
       // cout<<"OK"<<endl;
        printf("%d\n",solve());
    }

    return 0;
}
