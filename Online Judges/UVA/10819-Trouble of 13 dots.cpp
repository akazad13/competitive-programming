#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for( i = a; i<b;i++)
#define lld long long

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int n,make;
int dp[101][10201];
vector< pi > vec;


int solve(int ind, int take)
{
    if(ind>=n)
    {
       return 0;
    }

    lld ret1=0;
    lld ret2=0;

    if(dp[ind][take]!=-1)
        return dp[ind][take];

    if(take+vec[ind].first<=make || (take+vec[ind].first)>2000 && (take+vec[ind].first) <=make+200)
            ret1 = solve(ind+1,take+vec[ind].first)+vec[ind].second;

    ret2 = solve(ind+1,take);

    return dp[ind][take]=max(ret1,ret2);
}


bool cmp(pi a, pi b)
{
    if(a.first!=b.first)
    {
        return a.first<b.first;
    }

    return a.second>b.second;
}

int main()
{
   // freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,u,v;

    while(scanf("%d %d",&make,&n)==2)
    {
        vec.clear();

        rep(i,0,n+1)
        {
            rep(j,0,make+201)
            {
                dp[i][j]=-1;
            }
        }

        rep(i,0,n)
        {
            read(u); read(v);
            vec.pb(mp(u,v));
        }

        sort(vec.begin(),vec.end(),cmp);

        printf("%d\n",solve(0,0));
    }


    return 0;
}
