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



lld dp[11][30001];
int arr[12];

lld solve(int ind, int m)
{
    //cout<<m<<endl;
    if(ind>10)
    {
        if(m==0)
            return 1;
        else
            return 0;
    }
    if(m==0)
        return 1;

    if(dp[ind][m]!=-1) return dp[ind][m];

    lld ret=0;

    if(m>=arr[ind])
    {
        ret=solve(ind,m-arr[ind]);
    }
    ret+=solve(ind+1,m);

    return dp[ind][m]=ret;
}

int main()
{
    //freopen("input.txt","w",stdout);

    arr[0]= 5;
    arr[1]=10;
    arr[2]=20;
    arr[3]=50;
    arr[4]=100;
    arr[5]=200;
    arr[6]=500;
    arr[7]=1000;
    arr[8]=2000;
    arr[9]=5000;
    arr[10]=10000;

    double n;
    //double m;
    while(scanf("%lf",&n)==1)
    {
        if(n==0)
            break;
        Clear(dp,-1);

        int p = (int)(n*100 + 0.00001);

        lld ret = solve(0,p);
        printf("%6.2f",n);
        printf("%17lld\n",ret);
    }

    return 0;
}

