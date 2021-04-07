#include<iostream>
#include<bits/stdc++.h>

#define lld long long int
using namespace std;

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
          lld n;
          cin>>n;

          lld res  = ((-1+sqrt(1+8*n))/2);

          cout<<res<<"\n";
    }
    return  0;
}
