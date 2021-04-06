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

int main()
{
    int test,i,j,Case;
    lld n,c;

    read(test);
    rep(Case,1,test+1)
    {

        read(n); read(c);

        if(n==0)
            printf("Case %d: 0\n",Case);
        else
        {
            lld res = c/(2*n);
            if(c-n-2*n*res>0)
                res++;
            printf("Case %d: %lld\n",Case,res);
        }

    }

    return 0;
}



