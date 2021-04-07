#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;

    while(cin>>a>>b>>c)
    {
        if(a!=b&&a!=c)
            printf("A\n");
        else if(b!=a&&b!=c)
            printf("B\n");
        else if(c!=a&&c!=b)
            printf("C\n");
        else
            printf("*\n");
    }
    return 0;
}
