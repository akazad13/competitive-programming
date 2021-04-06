#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
#define Clear(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define lim 44
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

ll fib[lim];

ll sum[lim];


int main()
{
  //  freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    fib[1]=1;
    fib[2]=1;

    sum[1]=1;
    sum[2]=2;

    for(ll i=3;i<lim;i++)
    {
        fib[i] = fib[i-1]+fib[i-2];
        sum[i] = fib[i]+sum[i-1];
       // cout<<i<<" "<<sum[i]<<endl;
    }

   // cout<<sum[lim-1]<<endl;

    int test,Case;
    ll n;

    string str;

    read(test);
    rep(Case,1,test+1)
    {
        read(n);
        str.clear();

        int dig;

        for(int i=1;i<lim;i++)
        {
            if(sum[i]>=n)
            {
                dig=i;
                break ;
            }
        }

       // cout<<dig<<endl;

        for(int i=dig;i>=1;i--)
        {
            if(sum[i-1]<n && sum[i]>=n)
            {
                str+='1';
                n-=(sum[i-1]+1);
            }
            else
                str+='0';
        }

       printf("Case %d: ",Case);
       cout<<str<<"\n";
    }

    return 0;
}

