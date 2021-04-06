#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int coin;
    int no;
}data[60];

bool cmp( node a, node b)
{
    return a.coin<b.coin;
}

int dp[55][1100];
int solve(int ind , int make)
{
    if(make==0)
        return 1;

}

int main()
{
    int test,n,make,already;
    scanf("%d",&test);

    for(int Case =1 ;Case<=test;Case++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&make);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data[i].coin);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data[i].no);
        }

        sort(data,data+n,cmp);

        int way = solve(0,make);

        printf("Case %d: %d\n",Case,way);
    }
    return 0;
}
