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
    node arr[50010];
    bool vis[50010];
    lld ans;
    lld top;
    read(test);
    rep(Case,1,test+1)
    {
        ans=0;
        top=0;
        Clear(vis,0);
        read(n);
        read(m);
        rep(i,0,n)
        {
            read(arr[i].a);
            read(arr[i].b);
        }

        sort(arr,arr+n,cmp);
        i=0;

        while(i<n)
        {
            if(!vis[i])
            {
                top=arr[i].b;
                vis[i]=1;
                ans++;
                top+=m;
                i++;
            }
            while(top>=arr[i].b && i<n)
            {

                vis[i]=1;
                i++;
            }
        }
        printf("Case %d: %lld\n",Case,ans);

    }

    return 0;
}

