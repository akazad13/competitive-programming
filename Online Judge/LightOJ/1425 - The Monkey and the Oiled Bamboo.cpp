#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define fileRead(a) freopen("a","r",stdin)

#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)

int main()
{
    int test,i,j,Case;
    lld n,arr[100010],cur,ans,temp;
    read(test);
    rep(Case,1,test+1)
    {
        ans=0;
        Lread(n);
        cur=0;
        arr[0]=0;
        rep(i,1,n+1)
        {
            Lread(arr[i]);
        }
        for(i=n;i>0;i--)
        {
            temp=abs(arr[i]-arr[i-1]);
            if(temp==ans)
            {
                ans++;
            }
            else if(temp>ans)
            {
                ans=temp;
            }
        }

        printf("Case %d: %lld\n",Case,ans);

    }

    return 0;
}


