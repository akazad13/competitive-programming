#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstdio>

using namespace std;
#define ll                   long long
#define ulld                 unsigned long long int
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define scl2(n,m)            scanf("%lld %lld",&n,&m)
#define scl3(n,m,l)          scanf("%lld %lld %lld",&n,&m,&l)
#define scl4(n,m,l,k)        scanf("%lld %lld %lld %lld",&n,&m,&l,&k)
#define scd(n)               scanf("%lf",&n)
#define pll                  pair<ll,ll>
#define pb                   push_back
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define mset(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define uniquee(x)           x.erase(unique(x.begin(), x.end()),x.end())
#define print_vector(v)      for(ll i=0;i<(v.size());i++)cout<<v[i]<<" ";
#define v(a)                 vector<a>
#define ma(a,b)              map<a,b>
#define MAXN                 100005
#define eps                  0.0000000001
#define inf                  1e18
#define sortArr(a,n)         sort(a,a+n)
#define pi                   acos(-1.0)
#define gamma                0.5772156649015328606065120900824024310421


/* CheckList
    1. Can i solve the sub-problem of that problem
    2. Can i solve the whole problem
    3. Do i check the parameter
    4. Did i clear all the memory
    5. check whether DP is cleared
    6. Understand the prob?! check again!!!

*/

ll arr[1000010];

ll Kadane(ll n) {
    ll maxSum = -1*INT_MAX, cur = 0;
    for(int i=0;i<n;i++) {
        cur = max(arr[i], cur+arr[i]);
        maxSum = max(maxSum, cur);
    }
    return maxSum;
}

int main()
{
    ll n,test;
    scl(test);
    for (int Case = 1; Case <= test; Case++)
    {
        scl(n);
        for (int i = 0; i < n; i++)
        {
            scl(arr[i]);
        }
        ll maxSum = Kadane(n);
        printf("%lld\n", maxSum);
    }
    return 0;
}



