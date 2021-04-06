#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 1005

vector<int> Graph[Max];
int par[Max];
int dp[Max][2];

int cal(int u, int isCover)
{
    if(Graph[u].size()==0)
        return 1;
    if(dp[u][isCover]!=-1)
        return dp[u][isCover];
    int len= Graph[u].size();

    int i,v;
    int ret=0;
    rep(i,0,len)
    {
        v = Graph[u][i];

        if (v != par[u]) {
            par[v] = u;

        if(isCover)
            ret+= cal(v,0);
        else
            ret+= max(cal(v,0),cal(v,1));
        }
    }
    dp[u][isCover] = ret+isCover;
    return dp[u][isCover];
}

int main()
{
    int test,i,j,Case,ver,edge,u,v;
    read(test);
    rep(Case,1,test+1)
    {
        read(ver);
        read(edge);

        rep(i,0,1005)
        {
            Graph[i].clear();
        }

        Clear(par,0);
        Clear(dp,-1);

        rep(i,0,edge)
        {
            read(u); read(v);
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }

        int ret=0;

        rep(i,1,ver+1)
        {
            if(!par[i])
            {
                ret+=max(cal(i,0),cal(i,1));
            }
        }

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}
