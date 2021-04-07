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

vector< pi > vec;

int dp[32][1002];
int dir[32][1002];

int n,total,w;

void reset()
{
    int i,j;
    rep(i,0,n+2)
    {
        rep(j,0,total+2)
        {
            dp[i][j]=-1;
            dir[i][j]=-1;
            //cout<<dir[i][j]<<endl;
        }
    }
}

int solve(int ind, int tot)
{
    if(ind>=n || tot>total)
        return 0;
    if(dp[ind][tot]!=-1)
        return dp[ind][tot];

    int ret1=0;
    int ret2=0;

    int cost = (3*vec[ind].first*w);

    if(tot+cost<=total)
    {
        ret1 = solve(ind+1,tot+cost)+vec[ind].second;
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
    i=0;j=0;

    vector<pi> sol;

    while(dir[i][j]!=-1 && i<n && j<=total)
    {
        if(dir[i][j]==1 && j+(3*vec[i].first*w)<=total)
        {
            sol.pb(mp(vec[i].first,vec[i].second));
            j+=(3*vec[i].first*w);
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
        printf("%d %d\n",sol[i].first,sol[i].second);
    }

    return ;
}

int main()
{
    //freopen("inp.txt","r",stdin);
    int a,b,i;
    bool flag=0;

    while(scanf("%d",&total)==1)
    {
        vec.clear();

        read(w);
        read(n);

        reset();

        rep(i,0,n)
        {
            read(a);
            read(b);

            vec.pb(mp(a,b));
           // cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }

        int ret = solve(0,0);

        if(flag)
            printf("\n");
        flag=1;

        printf("%d\n",ret);
        printSol();
    }

    return 0;
}

