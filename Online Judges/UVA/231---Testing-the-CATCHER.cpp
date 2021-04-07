#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
#define mp make_pair

#define Clear(a,b) memset(a,b,sizeof(a))

#define  inf 32778

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int dp[103][32780];
int arr[103];
int dir[103][32780];

int n,total,w;

void reset()
{
    int i,j;
    rep(i,0,n+2)
    {
        rep(j,0,total+2)
        {
            dir[i][j]=-1;
            dp[i][j]=-1;
        }
    }

    rep(i,0,n+2)
        dp[i][32778]=-1;
}

int solve(int ind, int tot)
{
    if(ind>=n)
        return 0;
    if(dp[ind][tot]!=-1)
        return dp[ind][tot];

    int ret1=0;
    int ret2=0;

    //cout<<ind<<" "<<tot<<endl;

    if(tot>arr[ind])
    {
        ret1 = solve(ind+1,arr[ind])+1;
    }
    ret2 =  solve(ind+1,tot);

    if(ret1>=ret2)
    {
        dir[ind][tot]=1;
        return dp[ind][tot]=ret1;
    }
    else
    {
        dir[ind][tot]=2;
        return dp[ind][tot]=ret2;
    }
}


void printSol()
{
    int i,j;
    i=0;j=arr[i];

    vector<int> sol;

    while(dir[i][j]!=-1 && i<n && j<=total)
    {
        cout<<i<<" "<<j<<" "<<dir[i][j]<<endl;
        if(dir[i][j]==1)
        {
            sol.pb(arr[i]);
            j= arr[i];
            i++;
        }
        else
        {
            i++;
        }
    }

    printf("%d\n",sol.size());

    rep(i,0,sol.size())
    {
        printf("%d\n",sol[i]);
    }

    return ;
}

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    //freopen("inp.txt","r",stdin);
    int a,b,i,val,temp;
    int cnt=1;
    bool flag=0;
    while(1)
    {
        int Max = -23;
        int ind=0;
        while(scanf("%d",&val)==1)
        {
            if(temp==-1 && val==-1)
            {
                flag=1;
                break;
            }
            else if(val==-1)
            {
                temp=-1;
                break;
            }

            else
            {
                arr[ind++]=val;
                Max = max(Max,val);
            }
            temp=val;
        }

        if(flag)
            break;

       // sort(arr,arr+ind,cmp);

        n = ind;
        total = Max;
        reset();
        int ret = solve(0,inf);

        if(cnt>1)
            printf("\n");

        printf("Test #%d:\n  maximum possible interceptions: %d\n",cnt++,ret);

        //printSol();

    }

    return 0;
}


