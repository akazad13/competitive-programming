#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define read(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)

int dp[1005][35];
int Weight[1000],Cost[1000];

int n,people;

int NapSak(int index, int weight)
{
    if(index==n)
        return 0;
    if(dp[index][weight]!=-1)
        return dp[index][weight];

    int profit1=0,profit2=0;

    if(weight>=Weight[index])
        profit1=Cost[index]+NapSak(index+1,weight-Weight[index]);
    profit2 = NapSak(index+1,weight);
    dp[index][weight] = max(profit1,profit2);
    return dp[index][weight];
}

int main()
{
    //freopen("10130.txt","r",stdin);

    int test,weight, cost;
    read(test);

    for(int T = 1;T<=test;T++)
    {

        memset(dp,-1,sizeof(dp));
        read(n);
        for(int i=0;i<n;i++)
        {
            read(Cost[i]); read(Weight[i]);
        }

        read(people);
        int sum=0,W;
        //cout<<people<<endl;
        for(int i=0;i<people;i++)
        {
            read(W);
            //cout<<W<<endl;
            sum+=NapSak(0,W);
            //cout<<sum<<endl;
        }
        write(sum);

    }
    return 0;
}
