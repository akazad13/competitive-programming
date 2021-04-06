#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))


double cal(int n, int day)
{

    if(n>=day)
        return 1;
    double sum = 1;

    int p = n;

    for(int i = 1; day-i>0 && i<=n ;i++)
    {
        double m = (double)(day-i);
        sum = (sum*m*1.0);

        if(p>0)
        {
            p--;
            sum/=(day*1.0);
        }
    }

    if(day-n>=0)
    {

        while(p)
        {
            p--;
            sum/=(day*1.0);
        }
    }
    return 1-sum;
}

int solve(int n)
{
    int high,low,mid;

    low = 1;
    high = 1000;

    while(low<=high)
    {
        mid = (low+high)>>1;

        double ret = cal(mid,n);
        if(ret==.50)
            return mid ;
        else if(ret<.50)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }

    }

    return low;
}

int main()
{
    int test,i,j,Case;
    int n;
    scanf("%d",&test);
    rep(Case,1,test+1)
    {
        scanf("%d",&n);

        int ret = solve(n);

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}


