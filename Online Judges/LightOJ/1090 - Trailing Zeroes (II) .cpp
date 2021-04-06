#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long int

int main()
{
    int test;
    READ(test);
    int n,r,p,q;

    for(int t=1;t<=test;t++)
    {
        READ(n);READ(r);READ(p);READ(q);
        lld ans1=0,ans2=0,ans3=0,ans4=0;
        for(int i=5;i<=n;i*=5)
        {
            ans1+=n/i;
        }
        for(int i=5;i<=r;i*=5)
        {
            ans1-=r/i;
        }

        for(int i=5;i<=(n-r);i*=5)
        {
            ans1-=(n-r)/i;
        }

        for(int i=2;i<=n;i*=2)
        {
            ans2+=n/i;
        }

        for(int i=2;i<=r;i*=2)
        {
            ans2-=r/i;
        }

        for(int i=2;i<=(n-r);i*=2)
        {
            ans2-=(n-r)/i;
        }



        int l = p;

        while(l%2==0 && l>1)
        {
            ans3++;
            l/=2;
        }

        while(p%5==0 && p>1)
        {
            ans4++;
            p/=5;
        }

        ans3*=q;
        ans4*=q;

        lld res  = min(ans2+ans3,ans1+ans4);

        printf("Case %d: %lld\n",t,res);
    }

    return 0;

}
