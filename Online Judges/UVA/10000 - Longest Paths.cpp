#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp make_pair

#define Clear(a,b) memset(a,b,sizeof(a))

#define  inf -12200

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

int dp[103][103];
int arr[103];




int main()
{
    //freopen("inp.txt","r",stdin);
    int a,b,n,i,j,k;
    int st;
    int cnt=1;

    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;

        rep(i,0,n+1)
        {
            rep(j,0,n+1)
            {
                dp[i][j] = inf;
            }
        }

        read(st);

        while(read(a))
        {
            read(b);
            if(a==0 && b==0)
                break;
            dp[a][b]=1;
        }


        rep(k,1,n+1)
        {
            rep(i,1,n+1)
            {
                rep(j,1,n+1)
                {
                    if(dp[i][j]<dp[i][k]+dp[k][j])
                    {
                        dp[i][j] = dp[i][k]+dp[k][j];
                    }
                }
            }
        }

        int res = -1;
        int ind = -1;

        rep(i,1,n+1)
        {
            if(dp[st][i]>res && dp[st][i]!=inf)
            {
                res = dp[st][i];
                ind = i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cnt++,st,res,ind);

    }
    return 0;
}



