#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

struct node
{
    int a,b;
};

bool cmp(node p, node q)
{
    return p.b<q.b;
}

int main()
{

    int test,i,j,Case,n,m;
    char str[110];
    bool vis[110];
    int ans,cnt;
    char ch;

    read(test);
    rep(Case,1,test+1)
    {
        ans=0;
        cnt=0;
        Clear(vis,0);
        read(n);
        scanf("%c",&ch);

        gets(str);
        i=0;

        while(i<n)
        {
            if(cnt==1)
            {
                ans++;
                vis[i]=1;
                if(i<n)
                    vis[i+1]=1;
                i+=2;
                cnt=0;
            }
            if(str[i]=='.' && vis[i]==0 && i<n)
            {
                cnt++;
                vis[i]=1;
                i++;
            }
            else
            {
                i++;
            }
        }
        if(cnt!=0)
            ans++;
        printf("Case %d: %d\n",Case,ans);

    }

    return 0;
}


