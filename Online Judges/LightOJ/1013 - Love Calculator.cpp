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

char str1[32], str2[32];
int len1, len2;
int dp[32][32];
lld dp2[32][32][60];
int make;

int find_sub(int l1, int l2)
{
    if(l1==len1 && l2==len2)
        return 0;

    if(l1==len1)
        return (len2-l2);
    if(l2==len2)
        return (len1-l1);

    if(dp[l1][l2]!=-1) return dp[l1][l2];

    int ret1=INT_MAX;
    int ret2=INT_MAX;

    if(str1[l1]==str2[l2])
    {
        ret1 = find_sub(l1+1,l2+1)+1;
    }
    else
    {
        ret2 = min(find_sub(l1+1,l2),find_sub(l1,l2+1))+1;
    }

    return dp[l1][l2] = min(ret1,ret2);

}


lld find_str(int l1, int l2,int len)
{
    if(len==make)
    {
        if(l1==len1 && l2==len2)
            return 1;
        else
            return 0;
    }

    if(l1>=len1 && l2>=len2)
        return 0;
    if(l1==len1)
    {
        if(len2-l2+len==make)
            return 1;
        else
            return 0;
    }

    if(l2==len2)
    {
        if(len1-l1+len==make)
            return 1;
        else
            return 0;
    }

    if(dp2[l1][l2][len]!=-1) return dp2[l1][l2][len];
    lld ret=0;

    if(str1[l1]==str2[l2])
    {
        ret+= find_str(l1+1,l2+1,len+1);
    }
    else
    {
        ret+=find_str(l1+1,l2,len+1)+find_str(l1,l2+1,len+1);
    }

    return dp2[l1][l2][len] = ret;


}

int main()
{
    int test,i,j,Case,n,m;
    read(test);
    rep(Case,1,test+1)
    {
        Clear(dp,-1);
        gets(str1);
        gets(str2);

        len1 = strlen(str1);
        len2 = strlen(str2);


        make = find_sub(0,0);

        //cout<<make<<endl;

        Clear(dp2,-1);

        lld ret = find_str(0,0,0);

        printf("Case %d: %d %lld\n",Case, make, ret);
    }

    return 0;
}
