#include<iostream>
#include<bits/stdc++.h>

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

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
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

inline int Set(int N, int pos)
{
    return N= N|(1<<pos);
}

inline int Reset(int N, int pos)
{
    return N= N & ~(1<<pos);
}

inline bool check(int N, int pos)
{
    return (bool) (N&(1<<pos));
}
/************************************************************************************/

ll arr[100010];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    ll test,i,j,Case,n,m,d,l,p;
    read(test);
    rep(Case,1,test+1)
    {

        read(n); read(d); read(m); read(l);

        ll res=-1;

        for(ll i=0;i<n-1;i++)
        {
            ll low = m*i+l;
            ll high = (i+1)*m;

         //   cout<<low<<" "<<high<<endl;

            ll p = ceil(((double)low/(1.0*d)));

            ll q = high/d;

          //  cout<<p<<" "<<q<<" "<<low<<" "<<high<<endl;

            if(p<=q)
            {
                if(p*d==low)
                {
                    if(p<q && (p+1)*d <high)
                    {
                        res = (p+1)*d;
                    }
                }
                else if(p*d<high)
                {
                    res = p*d;
                }
            }

          //  cout<<res<<endl;

            if(res!=-1)
                break;
        }

        if(res==-1)
        {
            ll low  = ((n-1)*m+l);
            ll p  = ceil(((double)low/(1.0*d)));

            if(p*d==low)
                p++;
            res = p*d;
        }


        printf("Case %lld: %lld\n",Case,res);
    }

    return 0;
}


