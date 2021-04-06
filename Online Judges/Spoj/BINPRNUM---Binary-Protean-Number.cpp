#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))


long long int dp[100];

int main()
{
    //freopen("in1.txt","r",stdin);
    //freopen("out2.txt","w",stdout);

    int test,Case;
    char str[1000];

    scanf("%d",&test);
    char ch =getchar();

    Clear(dp,0);


    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<92;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }

    for(int i=2;i<92;i++)
    {
        dp[i]+=dp[i-1];
    }

    rep(Case,1,test+1)
    {
        scanf("%s",str);

        long long int res=0;
        int len = strlen(str);
        int k=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='0'|| str[i]=='1')
                str[k++]=str[i];
        }
        len=k;
        //res+=dp[len-1]+1;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='1')
            {
                res+=dp[len-i-1]+1;
            }
        }

        printf("Case %d: %lld\n",Case,res);
    }

    return 0;
}



