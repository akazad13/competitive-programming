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


int main()
{
   // freopen("in","r",stdin);
    //fileRead(in);
    int test,x1,x2,y1,y2;
    read(test);
    while(test--)
    {
        read(x1); read(y1); read(x2); read(y2);
        printf("%d %d\n",2*x2-x1,2*y2-y1);
    }
    return 0;
}

