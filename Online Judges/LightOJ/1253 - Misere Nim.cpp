#include<iostream>
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

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

    ll n,m,test,a[110];
    read(test);

    for(ll Case=1;Case<=test;Case++)
    {

        read(n);

        ll res = 0;
        bool flag=0;
        int cnt=0;

        for(ll i=0;i<n;i++)
        {

            read(a[i]);

            if(a[i]==1)
                cnt++;
            res^=a[i];

        }

        int no = n-cnt;
        if(no)
        {
            if(res)
                flag=1;
        }
        else
        {
            if(!(cnt&1))
            flag=1;

        }
        if(flag)
            printf("Case %lld: Alice\n",Case);
        else
            printf("Case %lld: Bob\n",Case);

    }
    return 0;
}
