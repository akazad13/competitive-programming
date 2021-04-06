#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long
#define PI acos(-1.0)

#define MOD 1000003

lld fact[1000010];

lld x, y;
void extendedEulid(lld a, lld b)
{
    if(b==0)
    {
        x=a; y=0;
        return ;
    }
    extendedEulid(b,a%b);
    lld x1 = y;
    lld y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}

int main()
{
    int test,n,take;

    fact[0]=1;

    for(int j=1;j<=1000000;j++)
    {
        fact[j]= (j * fact[j-1])%MOD;
    }


    READ(test);

    for(int i=1;i<=test;i++)
    {
        READ(n); READ(take);
        if(n<take)
        {
            printf("Case %d: 0\n",i);
            continue;
        }
        lld a = (fact[take]*fact[n-take])%MOD;
        extendedEulid(a,MOD);

        a = x;
        if(x<0)
            a+=MOD;
        printf("Case %d: %lld\n",i,(a*fact[n])%MOD);
    }
    return 0;
}


