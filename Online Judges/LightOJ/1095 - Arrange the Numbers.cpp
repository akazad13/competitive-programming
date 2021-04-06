#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
#define Clear(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define lim 1005
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

ll fact[lim];
ll ncr[lim][lim];

ll nCr(int n, int r)
{
    if(n==r || r==0)
        return 1;
    if(r==1)
        return n;

    if(ncr[n][r]!=-1) return ncr[n][r];

    ncr[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%mod;

    return ncr[n][r];
}

ll derangemant(int n, int it)
{
    ll ans = fact[n];

   // cout<<ans<<endl;

    for(int i=1;i<= it ;i++)
    {
        if(i%2)
            ans = (ans-nCr(it,i)*fact[n-i])%mod;
        else
            ans = (ans+nCr(it,i)*fact[n-i])%mod;
    }

     //cout<<ans<<endl;

    return (ans+mod)%mod;


}

int main()
{
  //  freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    fact[0]=1;

    for(ll i=1;i<lim;i++)
    {
        fact[i] = (i*fact[i-1])%mod;
    }
    Clear(ncr,-1);

    int test,Case;
    int n,m,k;

    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m); read(k);

        ll ret = (nCr(m,k)*derangemant(n-k,m-k))%mod; // nCk(m,k) = number of ways to choose k items
                                                      // at their initial position from first m
                                                      // derangement(p,q) = number of ways to arrange p number
                                                      // such that q number will not in the initial position


        printf("Case %d: %lld\n",Case,ret);
    }

    return 0;
}

