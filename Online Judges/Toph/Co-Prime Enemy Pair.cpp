#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
#define eps 1e-9
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)

#define MOD 1000000007
#define INF (1<<28)

#define Clear(a,b) memset(a,b,sizeof(a))
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

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}


template<typename T>inline T Dis(T x1,T y1,T x2, T y2)
{
    return sqrt( SQR(x1-x2) + SQR(y1-y2) );
}

template<typename T>inline T Angle(T x1,T y1,T x2, T y2)
{
    return atan( double(y1-y2) / double(x1-x2));
}
template<typename T>inline T DIFF(T a,T b)
{
    T d = a-b;
    if(d<0)return -d;
    else return d;
}
template<typename T>inline T ABS(T a)
{
    if(a<0)return -a;
    else return a;
}

template<typename T>inline T euclide(T a,T b,T &x,T &y)
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}

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

bool prime[1000100];

void sieve()
{
    for(int i=4;i<1000010;i+=2)
        prime[i]=1;

    int sq = sqrt(1000010);
    for(int i=3;i<=sq;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<1000010;j = j+2*i)
            {
                prime[j]=1;
            }
        }
    }

    return ;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int test,n;
    read(test);

    vector<ll> vec;

    for(int Case=1;Case<=test;Case++)
    {
        read(n);

        vec.clear();

        ll tot=0;

        for(ll i=2;i<=n;i++)
        {

            ll cnt=0;
            if(prime[i]==0)
            {
                //cout<<i<<endl;
                ll p=i;
                while(n>=p)
                {
                    cnt++;
                    p*=i;
                }
            }

            tot+=cnt;

            if(cnt)
                vec.push_back(cnt);
        }

        int len=vec.size();

        ll ans=0;

        for(int i=0;i<len;i++)
        {
            ll  p = vec[i];

            tot-=p;
            ans+= p*tot;
        }


        printf("Case %d: %lld\n",Case,ans);
    }

    return 0;
}
