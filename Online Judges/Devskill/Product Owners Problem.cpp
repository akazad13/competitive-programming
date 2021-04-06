#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
//#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
#define Mod 1000000007
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

lld dp[102][102];
struct node
{
    int Min, Max;
};

node arr[102];
int m;

lld solve(int ind, int n)
{
    if(n==0 && ind==m)
        return 1;
    if(ind>=m || n<0)
        return 0;

    if(dp[ind][n]!=-1)
        return dp[ind][n];

    lld res =0;

    for(int i=arr[ind].Min;i<=arr[ind].Max;i++)
    {
        if(n-i>=0)
        {
            res = (res+solve(ind+1,n-i))%Mod;
        }
    }

    //cout<<"res: "<<res<<" "<<ind<<" "<<n<<endl;

    dp[ind][n]=res;

    return dp[ind][n];
}


int main()
{
    //freopen("input.txt","r",stdin);

    int test,i,j,Case,n;

    read(test);

    rep(Case,1,test+1)
    {
        Clear(dp,-1);
        read(n);
        read(m);

        rep(i,0,m)
        {
            read(arr[i].Min);
            read(arr[i].Max);
        }

       // cout<<"______________________"<<endl;

        lld ret = solve(0,n);

        printf("Case %d: %lld\n",Case,ret);

    }

    return 0;
}


