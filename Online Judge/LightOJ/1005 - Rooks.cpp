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

lld nCr[31][31];

lld func(lld n, lld r)
{
    if(r==0)
        return 1;
    if(r==1)
        return n;

    if(n==r)
        return 1;

    if(nCr[n][r]!=-1) return nCr[n][r];

    nCr[n][r] = func(n-1,r-1)+func(n-1,r);

    return nCr[n][r];
}

int main()
{
    Clear(nCr,-1);
    int test,i,j,Case;
    lld n,k;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(k);

        printf("Case %d: ",Case);

        if(k>n)
        {
            printf("0\n");
            continue ;
        }

        lld ans=1;

        for(lld i = n ; i>(n-k);i--)
        {
            ans= ans*i;
        }

        printf("%lld\n",ans*func(n,k));
    }

    return 0;
}

