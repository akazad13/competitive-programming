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

template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}


/*****************************************/

#define Max 5000010

bool prime[Max+10];
VI pList;
int Vsize;

void sieve()
{
    Clear(prime,0);
    prime[0] = prime[1]=1;
    for(int i=4;i<=Max;i+=2)
    {
        prime[i]=1;
    }

    int sqr = sqrt(Max);

    for(int i=3;i<=sqr;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=Max;j = 2*i+j)
            {
                prime[j]=1;
            }
        }

    }

    for(int i=2;i<=Max;i++)
    {
        if(prime[i]==0)
        {
            pList.pb(i);
        }
    }

    Vsize = pList.size();
}

/*****************************************************/
lu dp[5000010];

int PI_f(int m)
{
    if(prime[m]==0)
    {
        return m-1;
    }
    ll res=1;

    for(int i=0;i<Vsize && pList[i]*pList[i]<=m;i++)
    {
        if(m<=1)
            break;
        if(m%pList[i]==0)
        {
            int cnt=0;
            while(m%pList[i]==0)
            {
                m/=pList[i];
                cnt++;
            }
            res = res*(pList[i]-1)*round(pow(pList[i],cnt-1)); // PI(n) = (p1^(a1-1))*(p1-1)*(p2^(a2-1))*(p2-1)*...
        }
        if(prime[m]==0 && m>1)
        {
            res = res*(m-1);
            break;
        }
    }

    return res;
}


int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    dp[0]=0;
    for(int i=2;i<=5000000;i++)
    {
        dp[i] = PI_f(i);
        dp[i]*=dp[i];
        dp[i]+=dp[i-1];
    }
    int test,Case,a,b;
    read(test);

    rep(Case,1,test+1)
    {
        read(a); read(b);
        lu res = dp[b]-dp[a-1];

        printf("Case %d: %llu\n",Case,res);
    }
    return 0;
}





