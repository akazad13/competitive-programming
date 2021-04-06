#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define Clear(a,b) memset(a,b,sizeof(a))

ll dp[12][12][2][2];
int len;
char str[15];

ll solve(int ind, int zero,int var, int flag)
{
    if(ind>=len)
    {
        return zero;
    }
    ll &ret = dp[ind][zero][var][flag];

    if(ret!=-1) return ret;

    ret=0;

    int en;

    if(var==0)
        en=9;
    else
        en=str[ind]-'0';

    if(en==0)
    {
        if(flag)
            return solve(ind+1,zero+1,var,flag);
        else
            return solve(ind+1,zero,var,flag);
    }

    if(flag)
        ret+=solve(ind+1,zero+1,0,flag);
    else
        ret+=solve(ind+1,zero,0,flag);


    for(int j=1;j<en;j++)
    {
        ret += solve(ind+1,zero,0,1);
    }
    ret += solve(ind+1,zero,var,1);
    return ret;
}

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,Case;
    char low[15];
    char high[15];

    scanf("%d",&test);
    for(Case = 1; Case<=test; Case++)
    {
        scanf(" %s %s",low,high);
        Clear(dp,-1);

        len = strlen(low);
        ll cnt=0;

        for(int i=0;i<len;i++)
        {
            str[i] = low[i];
            if(str[i]=='0')
                cnt++;
        }

        ll ret1 = solve(0,0,1,0);

        Clear(dp,-1);
        len = strlen(high);

        for(int i=0;i<len;i++)
        {
            str[i] = high[i];
        }


        ll ret2 = solve(0,0,1,0);

        //cout<<ret2<<" "<<ret1<<endl;

        ll res = ret2-ret1 +cnt;

        printf("Case %d: %lld\n",Case,res);
    }

    return 0;
}
