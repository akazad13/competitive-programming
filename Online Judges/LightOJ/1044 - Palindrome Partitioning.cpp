
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
/*****************************************************/
char str[1002];
int dp[1002];
bool ispalindrome[1002][1002];

int solve()
{
     int len = strlen(str);

     for (int i=0; i<len; i++)
    {
        ispalindrome[i][i] = true;
    }

    for (int k=2; k<=len; k++)
    {
        for (int i=0; i<len-k+1; i++)
        {
            int j = i+k-1; // Set ending index

            if (k == 2)
                ispalindrome[i][j] = (str[i] == str[j]);
            else
                ispalindrome[i][j] = (str[i] == str[j]) && ispalindrome[i+1][j-1];
        }
    }

    for (int i=0; i<len; i++)
    {
        if(ispalindrome[0][i]==1)
            dp[i] = 1;
        else
        {
            dp[i] = INT_MAX;
            for(int j=0;j<i;j++)
            {
                if(ispalindrome[j+1][i] == true && 1+dp[j]<dp[i])
                    dp[i]=1+dp[j];
            }
        }
    }

     return dp[len-1];

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

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



