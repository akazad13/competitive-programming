#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int
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
/************************************/

char str[16][16];
ll arr[16];
ll dp[(1<<16)+5];
int n;

ll solve(int mask)
{
    if(mask<0) return 0;
    if(mask==((1<<n)-1))
        return 0;

    if(dp[mask]!=-1) return dp[mask];

    ll ret = INT_MAX ;

    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int dam=1;
            for(int j=0;j<n;j++)
            {
                if(check(mask,j))
                {
                    dam = max(dam,str[j][i]-'0');
                }
            }

            ll temp = arr[i]/dam;

            if(arr[i]%dam)
                temp++;

            ret = min(ret,solve(Set(mask,i))+temp);
        }
    }

    return dp[mask] =ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        for(int i=0;i<=(1<<n);i++)
        {
            dp[i]=-1;
        }

        for(int i=0;i<n;i++)
            read(arr[i]);

        for(int i=0;i<n;i++)
            scanf(" %s",&str[i]);

        ll ret = solve(0);
        printf("Case %d: %lld\n",Case,ret);
    }

    return 0;
}
