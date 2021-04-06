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

/********************************************************/

double dp[1000010];

int main()
{

    Clear(dp,0);

    for(int i=1;i<=1000000;i++)
    {
        dp[i] = dp[i-1]+log10(i/1.0);
    }


    int test,Case,n,m;
    read(test);


    rep(Case,1,test+1)
    {
        read(n);
        read(m);

        ll p = 1+floor(dp[n]/(log10(m/1.0)));

      //  cout<<dp[n]<<" "<<

        printf("Case %d: %lld\n",Case,p);
    }



    return 0;
}







