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
#define mp(a,b) make_pair(a,b)

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

int n;
int arr[]={1,5,10,25,50};
lld dp[7][30005];


lld solve(int ind, int take)
{
    if(take==0)
    {
        return 1;
    }
    if(ind>=5)
        return 0;

   // cout<<ind<<" "<<take<<endl;

    lld ret1=0;
    lld ret2=0;

    if(dp[ind][take]!=-1)
        return dp[ind][take];

    if(take-arr[ind]>=0)
        ret1 = solve(ind,take-arr[ind]);

    ret2 = solve(ind+1,take);

    return dp[ind][take]=ret1+ret2;
}


int main()
{
   // freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int i,j;
    int cnt=1;

    Clear(dp,-1);


    //for(int i=0;i<5;i++)
       // cout<<arr[i]<<endl;

    while(scanf("%d",&n)==1)
    {

        lld ret = solve(0,n);
        if(ret==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",ret,n);
    }


    return 0;
}



