
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

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

/*****************************************/
char str[102];
int dp[102][102];

int solve()
{
     Clear(dp,0);
     int len = strlen(str);

     for(int j=1;j<len;j++)
     {
         int k=j;
         for(int i=0;i<len && k<len;i++,k++)
         {
             if(str[i]==str[k])
             {
                dp[i][k] = dp[i+1][k-1];
             }
             else
             {
                dp[i][k] = 1+min(dp[i][k-1],dp[i+1][k]);
             }
         }
     }
     return dp[0][len-1];
}

int main()
{
    int test,i,j,Case,n,m;
    char temp[10];
    read(test);
    rep(Case,1,test+1)
    {
        gets(str);
        int ret = solve();

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}


