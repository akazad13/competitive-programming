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

int n,k;

void solve(int len, bool used[], string str)
{
    if(k==0)
        return ;
    if(len==n)
    {
        cout<<str<<"\n";
        k--;
        return ;
    }

    for(int i=0;i<n;i++)
    {
        if(used[i]==0)
        {
            string temp = str;

            temp+= char(i+'A');

            used[i]=1;

            solve(len+1,used,temp);
            used[i]=0;
        }
    }
}

int main()
{

    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(k);

        printf("Case %d:\n",Case);

        bool used[30]={0};
        string str="";
        solve(0,used,str);
    }

    return 0;
}

