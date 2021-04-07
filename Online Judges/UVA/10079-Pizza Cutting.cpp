#include<iostream>
#include<bits/stdc++.h>

#define lld long long int

using namespace std;

int main()
{
    lld n;
    while(cin>>n)
    {
        if(n<0)
            break;
        cout<<((n*(n+1)/2)+1)<<"\n";
    }
    return 0;
}
