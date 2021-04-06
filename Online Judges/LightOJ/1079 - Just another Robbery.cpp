#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))

int n;
double tot_tol;

int pro[101];
double tol[101];

double dp[10001];

int solve(int sum)
{
    for(int i=0;i<=sum;i++)
        dp[i]=1;
    dp[0]=0;

    int ind;

    for(int j=0;j<n;j++)
    {
        for(int i=sum;i>=1;i--)
        {
            int ind = i-pro[j];

            if(ind>=0)
                dp[i] = min(dp[i],(dp[ind]+(1-dp[ind])*tol[j]));

        }
    }

    int ans=0;

    for(int i=1;i<=sum;i++)
    {
        if(dp[i]<tot_tol)
            ans=i;
    }

    return ans;
}

int main()
{
    int test,i,j,Case;
    scanf("%d",&test);
    rep(Case,1,test+1)
    {
        scanf("%lf %d",&tot_tol,&n);

        int sum=0;

        rep(i,0,n)
        {
            scanf("%d %lf",&pro[i],&tol[i]);
            sum+=pro[i];
        }

        int ret = solve(sum);

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}

