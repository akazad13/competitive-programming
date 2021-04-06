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
    lld n,sum=0,j;
    READ(test);

    for(int i=1;i<=test;i++)
    {
        sum=0;
        scanf("%lld",&n);
        int sqt = sqrt(n);
        for(j=1;j<=sqt;j++)
        {
            sum+=n/j+(n/j-n/(j+1))*j;
        }

        if(n/(j-1)==(j-1))
            sum-= (n/(j-1)-n/(j))*(j-1);

        printf("Case %d: %lld\n",i,sum);
    }
    return 0;
}
