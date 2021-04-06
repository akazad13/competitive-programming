#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define lld long long
#define PI acos(-1.0)


lld GCD(lld a, lld b)
{
    lld rem;
    while(b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }

    return a;
}

int main()
{
    int test;
    lld x1,x2,y1,y2;

    READ(test);

    for(int i=1;i<=test;i++)
    {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        lld res = GCD(abs(x1-x2),abs(y1-y2))+1;

        printf("Case %d: %lld\n",i,res);

    }

    return 0;

}

