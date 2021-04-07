#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

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

int n;
int coin[25];
lld dp[22][10001];

lld solve(int ind, int take)
{
    if(take==0)
        return 1;
    if(take<0 || ind>=n)
        return 0;

    if(dp[ind][take]!=-1) return dp[ind][take];
    dp[ind][take] = solve(ind,take-coin[ind])+solve(ind+1,take);
   // cout<<ind<<" "<<take<<" "<<dp[ind][take]<<endl;

    return dp[ind][take];
}


int main()
{
    //freopen("input.txt","r",stdin);



    int test,i,j,Case;
    n=21;
    int val;

    rep(i,0,21)
    {
        coin[i]= (i+1)*(i+1)*(i+1);
       // cout<<coin[i]<<endl;
    }

    while(read(val))
    {
        Clear(dp,-1);
        //cout<<n<<endl;
        cout<<solve(0,val)<<endl;
    }

    return 0;
}

