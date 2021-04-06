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

#define Max 100010

ll t1[4*Max], t2[4*Max];
ll a[Max], b[Max];

void build1(int node, int st, int eed)
{
    if(st==eed)
    {
        t1[node] = a[st];
        return ;
    }

    int left = node<<1;
    int right = left+1;

    int mid = (st+eed)>>1;

    build1(left,st,mid);
    build1(right,mid+1,eed);

    t1[node] = t1[left]+ t1[right];

    return ;
}

void build2(int node, int st, int eed)
{
    if(st==eed)
    {
        t2[node] = b[st];
       // cout<<node<<" "<<b[st]<<endl;
        return ;
    }

    int left = node<<1;
    int right = left+1;

    int mid = (st+eed)>>1;

    build2(left,st,mid);
    build2(right,mid+1,eed);

    t2[node] = t2[left]+ t2[right];

    return ;
}


ll query1(int node, int start, int eend, int l, int r)
{
    //cout<<start<<" "<<eend<<" "<<l<<" "<<r<<endl;
    if(start>r || eend<l)
        return 0;

    if(start>=l && eend<=r)
    {
        return t1[node];
    }

    int left = node<<1;
    int right = left+1;

    int mid = (start+eend)>>1;

    return query1(left,start,mid,l,r)+ query1(right,mid+1,eend,l,r);
}

ll query2(int node, int start, int eend, int l, int r)
{
   //  cout<<node<<" " <<start<<" "<<eend<<" "<<l<<" "<<r<<endl;
    if(start>r || eend<l)
        return 0;

    if(start>=l && eend<=r)
    {
        //cout<<node<<endl;
        return t2[node];
    }

    int left = node<<1;
    int right = left+1;

    int mid = (start+eend)>>1;

    return query2(left,start,mid,l,r)+ query2(right,mid+1,eend,l,r);
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,i,j,Case,n,m,q,aa,bb,cc,dd;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m);

        Clear(t1,0);
        Clear(t2,0);

        for(int i=1;i<=n;i++)
            read(a[i]);
        for(int i=1;i<=m;i++)
        {
            read(b[i]);
          //  cout<<b[i]<<endl;
        }

        build1(1,1,n);
        build2(1,1,m);

        read(q);
        printf("Case %d:\n",Case);

        while(q--)
        {
            read(aa); read(bb); read(cc); read(dd);

            ll ret1= query1(1,1,n,aa,bb);
            ll ret2 =query2(1,1,m,cc,dd);

          //  cout<<ret1<<" "<<ret2<<endl;

            printf("%lld\n",ret1*ret2);
        }
    }

    return 0;
}

