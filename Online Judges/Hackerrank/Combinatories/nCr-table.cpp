#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define fileRead(a) freopen("a","r",stdin)

#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define PR pair<int,int>
#define MP(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))

lld table[1005][1005];
#define MOD 1000000000

lld nCr(int n, int r)
{
    if(n==r)
        return 1;
    if(r==0)
        return 1;
    if(table[n][r]!=-1)
        return table[n][r];
    table[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%MOD;
    return table[n][r];
}


int main()
{
    //freopen("input.txt","r",stdin);

    Clear(table,-1);
    //nCr(1000)

    int test,i,j,n;
    read(test);
    for(int Case=1;Case<=test;Case++)
    {
        read(n);

        rep(i,0,n+1)
        {
            if(i==0)
                printf("%lld",nCr(n,i));
            else
                printf(" %lld",nCr(n,i));
        }
        printf("\n");
    }

    return 0;
}

