#include<iostream>
#include<cstdio>

using namespace std;
#define ll                   long long
#define scl(n)               scanf("%lld",&n)
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)

ll arr[1000010];

ll Kadane(ll n) 
{
    ll maxSum = -1*INT_MAX, cur = 0;
    LOOP(i,n) 
    {
        cur = max(arr[i], cur+arr[i]);
        maxSum = max(maxSum, cur);
    }
    return maxSum;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("IO/input.txt", "r", stdin);
        freopen("IO/output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ll n,test;
    scl(test);
    FOR(cs,test)
    {
        scl(n);
        LOOP(i,n)
        {
            scl(arr[i]);
        }
        ll maxSum = Kadane(n);
        printf("%lld\n", maxSum);
    }
    return 0;
}
