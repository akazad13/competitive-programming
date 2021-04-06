#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

int main()
{
    int test,i,j,Case,n;
    int arr[10002];

    scanf("%d",&test);

    bool vis[10010];

    rep(Case,1,test+1)
    {
        scanf("%d",&n);

        rep(i,0,n)
            vis[i]=0;

        bool flag=1;

        rep(i,0,n)
        {
            scanf("%d",&arr[i]);
        }

        sort(arr,arr+n);

        rep(i,0,n)
        {
            if(arr[i]>=n)
            {
                flag=0;
                break ;
            }

            else if(vis[arr[i]]==0)
            {
                vis[arr[i]]=1;
            }
            else if(vis[n-arr[i]-1]==0)
            {
                vis[n-arr[i]-1]=1;
            }
            else
            {
                flag=0;
                break;
            }
        }

        if(flag)
            printf("Case %d: yes\n",Case);
        else
            printf("Case %d: no\n",Case);
    }

    return 0;
}

