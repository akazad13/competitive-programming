#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
//istringstream is()

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

/******************************/

int R,B;
double dp[501][501][2];

double solve(int red, int blue, int turn)
{
    if(blue==0 && turn == 1 || red+blue==0)
        return 0;
    if(red+blue==1 && blue==1)
        return 1;

    if(dp[red][blue][turn]!=-1) return dp[red][blue][turn];

    double ret = 0;

    if(turn==0)
    {
        if(blue>0)
            ret+= blue*solve(red,blue-1,turn^1)/((red+blue)*1.0);
        if(red>0)
            ret+= red*solve(red-1,blue,turn^1)/((red+blue)*1.0);


    }
    else  // opponent always take blue marbel and his probability is 1
    {
        if(blue>0)
            ret = solve(red,blue-1,turn^1);
    }

    return dp[red][blue][turn] = ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case;

    for(int i=0;i<=500;i++)
    {
        for(int j=0;j<=500;j++)
        {
            for(int k=0;k<2;k++)
                dp[i][j][k]=-1;

        }
    }

    read(test);
    rep(Case,1,test+1)
    {
        read(R);
        read(B);

        double ret = solve(R,B,0);

        printf("Case %d: %.8f\n",Case,ret);
    }

    return 0;
}

