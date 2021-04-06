#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
#define lu unsigned long long int

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

ll a;

ll num_zero(ll n)
{
    ll res = 0;

    for(ll p = 5; p<=n;p = p*5)
    {
        res+=(n/p);
    }

    return res;
}

int main()
{
    int test,Case;
    read(test);

    rep(Case,1,test+1)
    {
        read(a);


        ll low = 1;
        ll high = 5000000000000000000;
        ll mid,res=-1;

        while(low<high)
        {
            mid  = (low+high)>>1;

            ll ret = num_zero(mid);

            if(ret==a)
            {
                res = mid;
                break;
            }

            else if(ret>a)
            {
                high = mid;
            }
            else
            {

                low = mid+1;
            }
        }
        if(res==-1)
        {
            printf("Case %d: impossible\n",Case);
            continue;
        }

        res = res-(res%5);

        printf("Case %d: %lld\n",Case,res);
    }



    return 0;
}







