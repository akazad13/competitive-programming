#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010
#define ll long long int
#define mod 1000000007

int n;

ll dp[33][2][2][33];
int arr[35];

ll solve(ll ind, ll pre, ll excl, ll sum)
{

    if(ind<0)
    {
       // cout<<sum<<endl;
        return sum;
    }

    if(ind!=n-1)
    {
        if(dp[ind][pre][excl][sum]!=-1) return dp[ind][pre][excl][sum];
    }

    ll ret=0;

    int en;

    if(excl==0)
        en=1;
    else
        en=arr[ind];


    for(int j=0;j<en;j++)
    {
        ret += solve(ind-1,0,0,sum);
    }
    if(pre==1 && en==1)
    {
       //cout<<pre<<" "<<ind<<endl;
        ret += solve(ind-1,1,excl,sum+1);
    }
    else
        ret += solve(ind-1,en,excl,sum);

    //cout<<"ret "<<ret<<" "<<ind<<endl;
    return dp[ind][pre][excl][sum] = ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

     ll test,Case, num;

    scanf("%lld",&test);

    for(Case =1 ;Case<=test;Case++)
    {


        for(int i=0;i<32;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                    {
                        for(int l=0;l<33;l++)
                            dp[i][j][k][l]=-1;

                      //  cout<<i<<endl;
                    }
            }
        }

        scanf("%lld",&num);

       // cout<<num<<endl;

        ll cnt=0;

        while(num)
        {
            arr[cnt] = num%2 ;
            num/=2;

            //cout<<arr[cnt]<<endl;
            cnt++;
        }
        n = cnt;
       // cout<<n<<endl;


        ll ret = solve(n-1,0,1,0);

        printf("Case %lld: %lld\n",Case,ret);
    }

    return 0;
}
