#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int
#define MOD 1000000007

lld x, y;
void extendedEulid( lld a, lld b)
{
    if(b==0)
    {
        x=1; y=0;
        return ;
    }
    extendedEulid(b, a%b);
    lld x1 = y;
    lld y1 = x - (a/b) *y;
    x = x1;
    y = y1;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("mine.txt","w",stdout);
    lld n,ans;
    extendedEulid(3,MOD);
    lld inv = (x+MOD)%MOD;
    //cout<<inv<<endl;
    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        scanf("%lld",&n);

        ans = n%MOD;
        ans = (ans * (n+1)%MOD)%MOD;
        ans = (ans * (n+2)%MOD)%MOD;
        ans = (ans*inv)%MOD;
        printf("Case %d: %lld\n",i,ans);
    }

    return 0;

}

