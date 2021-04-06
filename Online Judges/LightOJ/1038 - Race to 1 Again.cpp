#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 505

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

double dp[100010];

double solve(int n)
{
    int i,j;
    if(n<1)
        return 0;
    if(n==1)
    {
        return 0;
    }

    if(dp[n]!=-1) return dp[n];
    double ret=0;
    int cnt=0;

    for(int i=2;i<(int)sqrt(n)+1;i++)
    {
        if(n%i==0)
        {
            if((i*i)== sqrt(n)*sqrt(n))
            {
                ret+=solve(i);
                cnt++;
            }
            else
            {
                ret+=solve(i);
                ret+=solve(n/i);
                cnt+=2;
            }
        }
    }
    ret+=solve(1);
    cnt++;

    ret+=(cnt+1);

    ret = ret/(cnt*1.0);

    dp[n] = ret;
    return dp[n];
}

int main()
{

    int test,i,j,Case,n;
    rep(i,0,100001)
        dp[i]=-1;
    read(test);
    rep(Case,1,test+1)
    {

        read(n);
        if(n==1)
            printf("Case %d: 0\n",Case);
        else
            printf("Case %d: %.10f\n",Case,solve(n));
    }

    return 0;
}

