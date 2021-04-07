#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//#define Max 1001
int arr[10001];
//int sol[1001];
int dp1[10001];
int dp2[10001];
int cost[10001];

int LIS(int n)
{
    for(int i=0;i<n;i++)
    {
        dp1[i]=cost[i];
        //sol[i]=i;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp1[i] = max(dp1[i],dp1[j]+cost[i]);
              //  sol[i]=j;
            }
        }
    }

    int Max = -1;
    //int ind=-1;

    for(int i=0;i<n;i++)
    {
        //cout<<dp1[i]<<" ";
        if(Max<dp1[i])
        {
            Max = dp1[i];
          //  ind = i;
        }
    }

   // cout<<endl;

    return Max;
}


int LDS(int n)
{
    for(int i=0;i<n;i++)
    {
        dp2[i]=cost[i];
        //sol[i]=i;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                dp2[i] = max(dp2[i],dp2[j]+cost[i]);
              //  sol[i]=j;
            }
        }
    }

    int Max = -1;
    //int ind=-1;

    for(int i=0;i<n;i++)
    {
        //cout<<dp2[i]<<" ";
        if(Max<dp2[i])
        {
            Max = dp2[i];
          //  ind = i;
        }
    }

    //cout<<endl;

    return Max;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int n,test;
    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&cost[i]);

        int p = LIS(n);

        int q = LDS(n);

       // cout<<p<<" "<<q<<endl;

       if(p>=q)
       {
           printf("Case %d. Increasing (%d). Decreasing (%d).\n",Case,p,q);
       }
       else
       {
           printf("Case %d. Decreasing (%d). Increasing (%d).\n",Case,q,p);
       }
    }

    return 0;
}
