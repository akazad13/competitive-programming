
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
char str1[70];
char str2[70];
char str3[70];
int dp[55][55][55];

int len1,len2,len3;

int solve(int i, int j,int k)
{
    if(i>=len1 || j>=len2 || k>=len3)
        return 0;

    int &ret = dp[i][j][k];

    if(ret!=-1) return ret;

    if(str1[i]==str2[j]&& str2[j]==str3[k])
    {
        ret=1+solve(i+1,j+1,k+1);
    }
    else
    {
        ret=max(max(solve(i+1,j,k),solve(i,j+1,k)),solve(i,j,k+1));
    }
    return ret;
}

int main()
{
    int test,i,j,Case,n,m;
    char temp[10];
    read(test);
    rep(Case,1,test+1)
    {
        gets(temp);
        gets(str1);
        gets(str2);
        gets(str3);

        len1 = strlen(str1);
        len2 = strlen(str2);
        len3 = strlen(str3);

        Clear(dp,-1);

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int len3 = strlen(str3);

        int ret = solve(0,0,0);

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}

