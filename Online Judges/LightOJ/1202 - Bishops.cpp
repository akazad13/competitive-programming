#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define lld long long int

int main()
{
    lld r1,r2,c1,c2;
    int test;

    read(test);

    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);

        printf("Case %d:",Case);

        if((r1+c1)%2==0 && (r2+c2)%2==0 || (r1+c1)%2==1 && (r2+c2)%2==1)
        {
           if(abs(r1-r2)==abs(c1-c2))
           {
               printf(" 1\n");
           }
           else
            printf(" 2\n");
        }
        else
        {
            printf(" impossible\n");
        }
    }
    return 0;

}


