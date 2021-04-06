#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

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

int main()
{

    ll n,m,test,a[110],b[110];
    read(test);

    for(ll Case=1;Case<=test;Case++)
    {

        read(n);

        ll res = 0;

        for(ll i=0;i<n;i++)
        {
            read(a[i]);
        }

        for(ll i=0;i<n;i++)
        {
            read(b[i]);
        }

        for(ll i=0;i<n;i++)
        {
            ll p = b[i]-a[i]-1;
            res^=p;
        }

        if(res!=0)
            printf("Case %lld: white wins\n",Case);
        else
            printf("Case %lld: black wins\n",Case);

    }
    return 0;
}
