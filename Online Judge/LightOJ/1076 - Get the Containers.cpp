#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Clear(a,b) memset(a,b,sizeof(a))



lld arr[1010],n;

lld cap(lld val)
{
    lld ret=1,cur=0;

    int i,j;

    rep(i,0,n)
    {
        if(val<arr[i])
            return 10000000;
        else if(cur+arr[i]<=val)
        {
            cur+=arr[i];
        }
        else if(cur+arr[i]>val)
        {
            ret++;
            cur=arr[i];
        }
    }
    return ret;
}

lld solve(lld m)
{
    lld low=0;
    lld high=1000000000+1000;
    while(low<high)
    {
        if(low+1==high)
        {
            if(cap(low)>m)
                low = high;
            break;
        }

        int mid = (low+high)>>1;

        if(cap(mid)<=m)
            high = mid;
        else
            low = mid+1;
    }

    return low;
}

int main()
{
    int test,i,j,Case;
    lld m;

    read(test);
    rep(Case,1,test+1)
    {
        lld MaxC=-1;
        Lread(n);
        Lread(m);
        rep(i,0,n)
        {
            Lread(arr[i]);
            MaxC = max(MaxC,arr[i]);
        }

        if(n<=m)
        {
            printf("Case %d: %lld\n",Case,MaxC);
        }
        else
            printf("Case %d: %lld\n",Case,solve(m));

    }

    return 0;
}

