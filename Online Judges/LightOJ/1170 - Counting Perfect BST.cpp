#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
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

template <class T> inline T bigmod(T p,T e,T M){
    lld ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


lld dp[1000000];

int main()
{
    VL vec;
    lld sum=1;

    for(int i=2;i<=100000;i++)
    {
        sum=i;
        while(sum<=10000000000)
        {
            sum*=(lld)i;
            vec.pb(sum);
        }
    }

    sort(vec.begin(),vec.end());
    unique(vec.begin(),vec.end());

    lld mod = 100000007;

    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<1000000;i++)
    {
        dp[i] = (dp[i-1]*(lld)i)%mod;
    }

    int test,i,j,Case;
    lld a,b;
    read(test);
    rep(Case,1,test+1)
    {
        read(a); read(b);
        lld n = lower_bound(vec.begin(),vec.end(),b+1)-lower_bound(vec.begin(),vec.end(),a);
        lld res = dp[2*n];
        lld p = modinverse(dp[n],mod);
        lld q = modinverse((dp[n+1]),mod);
        res = (((res*p)%mod)*q)%mod;

        printf("Case %d: %lld\n",Case,res);
    }
    return 0;
}

