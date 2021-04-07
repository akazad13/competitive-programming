#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int t, m,n,o;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>m>>n;
            printf("%.0ld\n",((m/3)*(n/3)));
        }

    }
    return 0;
}
