#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define Clear(a,b) memset(a,b,sizeof(a))
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

char str[55];
int dp[55][4][6];
int len;

bool isvol(char s)
{
    //cout<<s<<endl;
    if(s=='A' || s=='E' || s=='O' || s=='I' || s=='U')
        return 1;
    return 0;
}

int bad(int ind, int vow, int con)
{
   // cout<<ind<<" "<<vow<<" "<<con<<" "<<len<<endl;
    if(vow>=3 || con>=5)
        return 1;
    if(ind>=len)
    {
        return 0;
    }



    if(dp[ind][vow][con]!=-1) return dp[ind][vow][con];

    int ret=0;

    if(str[ind]=='?')
    {
      //  cout<<ind<<" "<<vow<<endl;
        ret = max(ret,bad(ind+1,vow+1,0));
       // cout<<ret<<endl;
        ret = max(ret,bad(ind+1,0,con+1));
    }
    else
    {
        if(isvol(str[ind]))
        {
            ret = bad(ind+1,vow+1,0);
        }
        else
        {
            ret = bad(ind+1,0,con+1);
        }

     //   cout<<ind<<" "<<vow<<" "<<con<<endl;
    }

    return dp[ind][vow][con] = ret;
}


int good(int ind, int vow, int con)
{
    if(vow>=3 || con>=5)
        return 0;
    if(ind>=len)
    {
        return 1;
    }



    if(dp[ind][vow][con]!=-1) return dp[ind][vow][con];

    int ret=0;

    if(str[ind]=='?')
    {
        ret = max(ret,good(ind+1,vow+1,0));
        ret = max(ret,good(ind+1,0,con+1));
    }
    else
    {
        if(isvol(str[ind]))
        {
            ret = good(ind+1,vow+1,0);
        }
        else
        {
            ret = good(ind+1,0,con+1);
        }


    }

    return dp[ind][vow][con] = ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case,n,m;
    read(test);
    //char ss = getchar();
    rep(Case,1,test+1)
    {
        //scanf(" %s",&str);
        gets(str);
        len = strlen(str);

        Clear(dp,-1);

        int g = good(0,0,0);

        if(g==0)
            printf("Case %d: BAD\n",Case);
        else
        {
            Clear(dp,-1);
            g = bad(0,0,0);

            if(g==0)
                printf("Case %d: GOOD\n",Case);
            else
                printf("Case %d: MIXED\n",Case);
        }

    }

    return 0;
}

