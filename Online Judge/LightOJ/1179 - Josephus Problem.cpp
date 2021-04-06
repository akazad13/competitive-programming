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

lld solve(lld n, lld k)
{
    if(n==1)
    {
        return 0;
    }

    return (solve(n-1,k)+k)%n;
}

int main()
{
    int test,i,j,Case;
    lld n, k;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(k);

        lld ret = solve(n,k);
        printf("Case %d: %lld\n",Case,ret+1);

    }

    return 0;
}


