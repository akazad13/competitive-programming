#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
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

/***************************************/

int n,q,d;

lld dp[202][12][22];
int arr[202];

int cal(int p, int q)
{
    lld ans = p+q;
    ans%=d;
    if(ans<0)
        ans+=d;
    return (int) ans;
}

lld solve(int ind, int take, int rem)
{
   if(take==0)
   {
       if(rem==0)
        return 1;
       else
        return 0;
   }
    if(ind>=n)
    {
        if(rem==0 && take==0)
            return 1;
        else
            return 0;
    }
    lld &ret = dp[ind][take][rem];

    if(ret!=-1) return ret;

    ret=0;

    if(take>0)
    {
        ret+=solve(ind+1,take-1,cal(rem,arr[ind]));
    }
    ret+=solve(ind+1,take,rem);

    return ret;
}

int main()
{

    int test,i,j,Case;
    scanf("%d",&test);
    int m;
    rep(Case,1,test+1)
    {
        read(n); read(q);

        rep(i,0,n)
            read(arr[i]);
        printf("Case %d:\n",Case);

        while(q--)
        {
            read(d); read(m);
            Clear(dp,-1);
            printf("%lld\n",solve(0,m,0));
        }

    }

    return 0;
}



