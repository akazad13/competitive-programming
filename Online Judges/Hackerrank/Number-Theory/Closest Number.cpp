#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int


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
#define MOD 1000000007


int main()
{
   // freopen("input.txt","r",stdin);

    int test,i,j;
    lld a,b,x;
    read(test);
    for(int Case=1;Case<=test;Case++)
    {
        scanf("%lld %lld %lld",&a,&b,&x);

        lld res = round(pow(a,b)) + x/2;

        printf("%lld\n",res-res%x);

    }

    return 0;
}


