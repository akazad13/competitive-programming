#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int

int main()
{
    int test,n;
    lld res,j;
    cin>>test;
    for(int Case =1 ; Case<=test; Case++)
    {
        scanf("%d",&n);
        res=0;
        for(int i=2;i*i<=n;i++)
        {
            j = n/i;

            res+=(((j+i)*(j-i+1))/2)+(j-i)*i;
        }
        printf("Case %d: %lld\n",Case,res);
    }

    return 0;
}
