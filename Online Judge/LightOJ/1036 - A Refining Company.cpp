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
/****************************************/

ll n,m;

ll radium[502][502], uranium[502][502];
ll dp[502][502];

ll solve(int p, int q)
{
    if(p<0 || q<0)
        return 0;


    if(dp[p][q]!=-1) return dp[p][q];

    ll t1 = solve(p,q-1)+radium[p][q];
    ll t2 = solve(p-1,q)+uranium[p][q];

    return dp[p][q] = max(t1,t2);;
}


int main()
{
    int test,Case;
    ll num;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                dp[i][j]=-1;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                read(uranium[i][j]);
                if(j>0)
                    uranium[i][j]+=uranium[i][j-1];

            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                read(radium[i][j]);

                if(i>0)
                    radium[i][j]+=radium[i-1][j];

            }
        }

        ll ret  = solve(n-1,m-1);

        printf("Case %d: %lld\n",Case,ret);

    }

    return 0;
}



